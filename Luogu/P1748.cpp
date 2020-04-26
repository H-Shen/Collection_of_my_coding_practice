#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

constexpr int MAXN = 10005;
ll dp[MAXN];

int main() {

    // pre
    dp[0] = 1;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for (int i = 1; i < MAXN; ++i) {
        dp[i] = min({dp[a]*2, dp[b]*3, dp[c]*5, dp[d]*7});
        if (dp[i] == dp[a] * 2) {
            ++a;
        }
        if (dp[i] == dp[b] * 3) {
            ++b;
        }
        if (dp[i] == dp[c] * 5) {
            ++c;
        }
        if (dp[i] == dp[d] * 7) {
            ++d;
        }
    }
    int index;
    IO::read(index);
    IO::writeln(dp[index - 1]);
    return 0;
}
