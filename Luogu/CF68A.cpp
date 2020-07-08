#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {

    int p1, p2, p3, p4, a, b;
    IO::read(p1, p2, p3, p4, a, b);
    int counter = 0;
    for (int i = a; i <= b; ++i) {
        if (i % p1 == i && i % p2 == i && i % p3 == i && i % p4 == i) {
            ++counter;
        }
    }
    IO::writeln(counter);

    return 0;
}

