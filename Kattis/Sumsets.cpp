// https://open.kattis.com/problems/sumsets
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

const int maxn = 4005;
const ll minVal = -536870920;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll A[maxn];
gp_hash_table<ll, pair<ll, ll>, custom_hash> ab;

namespace FastIO {

    static constexpr int MAXSIZE = 1024 * 1024;
    static char inputBuffer[MAXSIZE];
    static char *ptr1 = inputBuffer + MAXSIZE;
    static char *ptr2 = inputBuffer + MAXSIZE;

    inline static
    char getcharUsingFread() {
        if (ptr1 == ptr2) {
            ptr1 = inputBuffer;
            ptr2 = inputBuffer + fread(inputBuffer, 1, MAXSIZE, stdin);
            if (ptr1 == ptr2) {
                return EOF;
            }
        }
        return *ptr1++;
    }

    template<typename T>
    inline static
    void readIntUsingFread(T &x) {
        x = 0;
        bool isNeg = false;
        char ch = getcharUsingFread();

        // skip all non digit characters
        while (!isdigit(ch)) {
            if (ch == '-') {
                isNeg = true;
            }
            ch = getcharUsingFread();
        }

        while (isdigit(ch)) {
            x = x * 10 + static_cast<T>(ch ^ 48);
            ch = getcharUsingFread();
        }
        x = isNeg ? -x : x;
    }

    static char outputBuffer[MAXSIZE];
    static char *ptr = outputBuffer;

    inline static
    void putcharWithFwrite(const char &ch) {
        if (ptr - outputBuffer == MAXSIZE) {
            fwrite(outputBuffer, 1, MAXSIZE, stdout);
            ptr = outputBuffer;
        }
        *ptr++ = ch;
    }

    template<class T>
    inline static
    void writeIntWithFwrite(T x) {
        if (x < 0) {
            x = -x;
            putcharWithFwrite('-');
        }
        static int storeDigits[40];
        int top = 0;
        do {
            storeDigits[top++] = x % 10;
            x /= 10;
        } while (x);
        while (top) {
            putcharWithFwrite(static_cast<T>(storeDigits[--top]) + 48);
        }
    }

    // Execute this function after using writeIntWithFwrite() on all numbers for output.
    void flushAfterWriteIntWithFwrite() {
        fwrite(outputBuffer, 1, ptr - outputBuffer, stdout);
    }
}

int main() {

    int n;
    FastIO::readIntUsingFread(n);
    for (int i = 0; i < n; ++i) {
        FastIO::readIntUsingFread(A[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ab[A[i] + A[j]] = make_pair(A[i], A[j]);
        }
    }
    ll max_d = minVal;
    ll c, d, a, b;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d = A[i];
            c = A[j];
            if (ab.find(d - c) != ab.end()) {
                a = ab[d - c].first;
                b = ab[d - c].second;
                if (d != a && d != b && c != a && c != b) {
                    max_d = max(max_d, d);
                }
            }
            d = A[j];
            c = A[i];
            if (ab.find(d - c) != ab.end()) {
                a = ab[d - c].first;
                b = ab[d - c].second;
                if (d != a && d != b && c != a && c != b) {
                    max_d = max(max_d, d);
                }
            }
        }
    }
    if (max_d == minVal) {
        FastIO::putcharWithFwrite('n');
        FastIO::putcharWithFwrite('o');
        FastIO::putcharWithFwrite(' ');
        FastIO::putcharWithFwrite('s');
        FastIO::putcharWithFwrite('o');
        FastIO::putcharWithFwrite('l');
        FastIO::putcharWithFwrite('u');
        FastIO::putcharWithFwrite('t');
        FastIO::putcharWithFwrite('i');
        FastIO::putcharWithFwrite('o');
        FastIO::putcharWithFwrite('n');
    }
    else {
        FastIO::writeIntWithFwrite(max_d);
    }
    FastIO::putcharWithFwrite('\n');
    FastIO::flushAfterWriteIntWithFwrite();
    return 0;
}
