#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 9;

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

    int n, L, G;
    IO::read(n, L, G);
    int a, b;
    for (int i = 0; i < n; ++i) {
        IO::read(a, b);
        while (a > G || b > G) {
            a /= 2;
            b /= 2;
        }
        if (a < L || b < L) {
            puts("Too Young");
        } else if (a == b) {
            puts("Sometimes Naive");
        } else {
            puts("Too Simple");
        }
    }

    return 0;
}
