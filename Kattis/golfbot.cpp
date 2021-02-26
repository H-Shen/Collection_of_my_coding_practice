// https://open.kattis.com/problems/golfbot

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace FFT {

    constexpr int LOG_MAX_LENGTH = 27;
    constexpr int MODULUS = 2013265921;
    constexpr int PRIMITIVE_ROOT = 137;
    constexpr int PRIMITIVE_ROOT_INVERSE = 749463956;

    int addMultiply(int x, int y, int z) {
        return (int)((x + y * static_cast<ll>(z)) % MODULUS);
    }

    void transform(const vector<int> &a, vector<int> &tA,
                   int logN, int primitiveRoot) {
        tA.resize(1 << logN);
        for (int j = 0; j < (int) a.size(); j++) {
            unsigned int k = j << (32 - logN); // MUST be unsigned
            k = ((k >> 1) & 0x55555555) | ((k & 0x55555555) << 1);
            k = ((k >> 2) & 0x33333333) | ((k & 0x33333333) << 2);
            k = ((k >> 4) & 0x0f0f0f0f) | ((k & 0x0f0f0f0f) << 4);
            k = ((k >> 8) & 0x00ff00ff) | ((k & 0x00ff00ff) << 8);
            tA[(k >> 16) | (k << 16)] = a[j];
        }
        int root[LOG_MAX_LENGTH];
        root[LOG_MAX_LENGTH - 1] = primitiveRoot;
        for (int i = LOG_MAX_LENGTH - 1; i > 0; i--) {
            root[i - 1] = addMultiply(0, root[i], root[i]);
        }
        for (int i = 0; i < logN; i++) {
            int twiddle = 1;
            for (int j = 0; j < (1 << i); j++) {
                for (int k = j; k < (int) tA.size(); k += 2 << i) {
                    int x = tA[k];
                    int y = tA[k + (1 << i)];
                    tA[k] = addMultiply(x, twiddle, y);
                    tA[k + (1 << i)] =
                            addMultiply(x, MODULUS - twiddle, y);
                }
                twiddle = addMultiply(0, root[i], twiddle);
            }
        }
    }

    void multiply (const vector<int>& a,
                   const vector<int>& b,
                   vector<int>& res) {
        int minN = int(a.size() - 1 + b.size());
        int logN = 0;
        while ((1 << logN) < minN) {
            logN++;
        }
        vector<int> tA, tB, nC;
        transform(a, tA, logN, PRIMITIVE_ROOT);
        transform(b, tB, logN, PRIMITIVE_ROOT);
        for (int j = 0; j < (int)tA.size(); j++)
            tA[j] = addMultiply(0, tA[j], tB[j]);
        transform(tA, nC, logN, PRIMITIVE_ROOT_INVERSE);
        res.resize(minN);
        int nInverse = MODULUS - ((MODULUS - 1) >> logN);
        for (int j = 0; j < minN; j++)
            res[j] = addMultiply(0, nInverse, nC[j]);
    }
}

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }
    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

constexpr int MAXN = 200001;
vector<int> S(MAXN);
vector<int> P;
int n, m;

int main() {

    IO::read(n);
    int maxVal = -1;
    int val;
    for (int i = 0; i < n; ++i) {
        IO::read(val);
        S.at(val) = 1;
        maxVal = max(maxVal, val);
    }
    FFT::multiply(S, S, P);
    int s_length = maxVal + 1;
    for (int i = 0; i < s_length; ++i) {
        if (S.at(i)) {
            P.at(i) = 1;
        }
    }

    IO::read(m);
    int counter = 0;
    for (int i = 0; i < m; ++i) {
        IO::read(val);
        if (P.at(val) > 0) {
            ++counter;
        }
    }
    IO::writeln(counter);

    return 0;
}
