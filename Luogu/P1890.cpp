#include <bits/extc++.h>

using namespace std;
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

namespace SparseTable_Gcd {
    constexpr int MAXN = 1005;
    constexpr int LOGN = 14; // static_cast<int>(floor(log2(MAXN))+5)
    vector<vector<ll> > sptGcd(MAXN, vector<ll>(LOGN));
    array<ll, MAXN> Log2;

    constexpr void pre() {
        // init Log2[] in O(log n)
        Log2.at(1) = 0;
        Log2.at(2) = 1;
        for (int i = 3; i < MAXN; ++i) {
            Log2.at(i) = Log2.at(i / 2) + 1;
        }
    }

    void init(int n) {
        for (int j = 1; j <= SparseTable_Gcd::LOGN; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                SparseTable_Gcd::sptGcd.at(i).at(j) = std::gcd(
                        SparseTable_Gcd::sptGcd.at(i).at(j - 1),
                        SparseTable_Gcd::sptGcd.at(i + (1 << (j - 1))).at(j - 1));
            }
        }
    }
}

int main() {

    SparseTable_Gcd::pre();
    int n, m, x, y;
    ll s, ans;
    IO::read(n, m);
    for (int i = 1; i <= n; ++i) {
        IO::read(SparseTable_Gcd::sptGcd.at(i).at(0));
    }
    SparseTable_Gcd::init(n);
    while (m--) {
        IO::read(x, y);
        s = SparseTable_Gcd::Log2.at(y - x + 1);
        ans = std::gcd(SparseTable_Gcd::sptGcd.at(x).at(s),
                     SparseTable_Gcd::sptGcd.at(y - (1 << s) + 1).at(s));
        IO::writeln(ans);
    }

    return 0;
}
