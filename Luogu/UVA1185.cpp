#include <iostream>
#include <cmath>

using namespace std;

const double ln_10 = log(10.0);

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

int reback(int N) {
    return ceil((N * log(double(N)) - N + 0.5 * log(2.0 * N * M_PI)) / ln_10);
}

int main() {

    int n, p;
    IO::read(n);
    while (n--) {
        IO::read(p);
        if (p <= 1) {
            IO::writeln(1);
        } else {
            IO::writeln(reback(p));
        }
    }

    return 0;
}



