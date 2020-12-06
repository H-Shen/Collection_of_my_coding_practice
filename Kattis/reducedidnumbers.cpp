// https://open.kattis.com/problems/reducedidnumbers
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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

constexpr int MAXN = 1e6 + 5;
bitset<MAXN> vis;
vector<int> A;

int main() {

    int n, temp;
    IO::read(n);
    A.resize(n);
    for (auto &i : A) IO::read(i);
    bool haveAns;
    for (int m = 1;; ++m) {
        vis.reset();
        haveAns = true;
        for (const auto &i : A) {
            temp = i % m;
            if (vis[temp]) {
                haveAns = false;
                break;
            } else {
                vis[temp] = true;
            }
        }
        if (haveAns) {
            IO::writeln(m);
            break;
        }
    }

    return 0;
}
