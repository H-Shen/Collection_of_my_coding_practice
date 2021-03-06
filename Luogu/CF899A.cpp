#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

array<int, 3> stats;

int main() {

    int n, val;
    IO::read(n);
    while (n--) {
        IO::read(val);
        ++stats[val];
    }
    if (stats[1] <= stats[2]) {
        IO::writeln(stats[1]);
    } else {
        int counter = stats[2];
        stats[1] -= stats[2];
        counter += stats[1] / 3;
        IO::writeln(counter);
    }

    return 0;
}
