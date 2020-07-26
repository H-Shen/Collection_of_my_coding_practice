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

inline static
ll solve(ll x, ll y) {
    ll steps, extra_steps;
    x = abs(x);
    y = abs(y);
    if (x > y) {
        swap(x, y);
    }
    if (y <= 2 * x) {
        if (x == 2 && y == 2) {
            steps = 4;
        } else {
            steps = (x + y) / 3 + (x + y) % 3;
        }
    } else {
        if (x == 0 && y == 1) {
            steps = 3;
        } else {
            steps = x;
            extra_steps = (y - 2 * x) % 4;
            steps += extra_steps;
            // Remove the effect of all extra steps
            steps += (y - 2 * x - extra_steps) / 2;
        }
    }
    return steps;
}

int main() {

    ll x_p, y_p, x_s, y_s;
    IO::read(x_p, y_p, x_s, y_s);
    x_s -= x_p;
    y_s -= y_p;
    IO::writeln(solve(x_s, y_s));

    return 0;
}