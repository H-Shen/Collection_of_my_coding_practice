#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 1005;
constexpr ll MOD = 100003;

vector<vector<ll> > dp(MAXN, vector<ll>(MAXN));
vector<vector<bool> > obstacles(MAXN, vector<bool>(MAXN, false));

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

int main() {

    int n, m, x, y;
    IO::read(n, m);
    while (m--) {
        IO::read(x, y);
        obstacles.at(x).at(y) = true;
    }
    dp.at(1).at(0) = 1;
    for(int i = 1; i <= MAXN - 1;i++) {
        for(int j = 1; j <= MAXN - 1; j++) {
            if (!obstacles.at(i).at(j)) {
                dp.at(i).at(j) = (dp.at(i).at(j - 1) % MOD + dp.at(i - 1).at(j) % MOD) % MOD;
            }
        }
    }
    IO::writeln(dp.at(n).at(n));
    return 0;
}