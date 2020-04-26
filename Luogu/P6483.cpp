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

    int R, B, a_plus_b;
    IO::read(R, B);
    a_plus_b = (R - 4) / 2;
    for (int a = 1; a < a_plus_b; ++a) {
        int b = a_plus_b - a;
        if (a * b == B) {
            a += 2;
            b += 2;
            IO::write(max(a, b));
            putchar_unlocked(' ');
            IO::writeln(min(a, b));
            return 0;
        }
    }

    return 0;
}

