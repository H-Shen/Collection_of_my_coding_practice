#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
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

namespace SparseTable {
    constexpr int MAXN = 100003;
    constexpr int LOGN = 20; // static_cast<int>(floor(log2(MAXN))+2)
    vector<vector<int> > sptMin(MAXN, vector<int>(LOGN));
    vector<int> Log2(MAXN);

    void pre() {
        // init Log2[] in O(log n)
        Log2.at(1) = 0;
        Log2.at(2) = 1;
        for (int i = 3; i < MAXN; ++i) {
            Log2.at(i) = Log2.at(i >> 1) + 1;
        }
    }

    void init(int n) {
        for (int j = 1; j <= SparseTable::LOGN; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                SparseTable::sptMin.at(i).at(j) = min(
                        SparseTable::sptMin.at(i).at(j - 1),
                        SparseTable::sptMin.at(i + (1 << (j - 1))).at(j - 1));
            }
        }
    }
}

int main() {

    SparseTable::pre();
    int n, m;
    IO::read(n, m);
    for (int i = 1; i <= n; ++i) {
        IO::read(SparseTable::sptMin.at(i).at(0));
    }
    SparseTable::init(n);
    int x, y, s, minVal;
    for (x = 1, y = m; x <= n - m + 1; ++x, ++y) {
        s = SparseTable::Log2.at(y - x + 1);
        minVal = min(SparseTable::sptMin.at(x).at(s),
                     SparseTable::sptMin.at(y - (1 << s) + 1).at(s));
        IO::writeln(minVal);
    }

    return 0;
}
