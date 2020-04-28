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

int main() {

    ll L, p;
    IO::read(L, p);
    ll total = L * p;
    ll a, b, c, d, e;
    IO::read(a, b, c, d, e);
    IO::write(a - total);
    putchar_unlocked(' ');
    IO::write(b - total);
    putchar_unlocked(' ');
    IO::write(c - total);
    putchar_unlocked(' ');
    IO::write(d - total);
    putchar_unlocked(' ');
    IO::writeln(e - total);

    return 0;
}