#include <bits/extc++.h>

using namespace std;
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

int main() {

    int n, sum, a_copy;
    IO::read(n);
    for (int a = n;; ++a) {
        sum = 0;
        a_copy = a;
        while (a_copy > 0) {
            sum += a_copy % 10;
            a_copy /= 10;
        }
        if (sum % 4 == 0) {
            IO::writeln(a);
            break;
        }
    }

    return 0;
}
