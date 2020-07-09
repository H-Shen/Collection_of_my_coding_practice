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

    int n, m, val;
    IO::read(n, m);
    vector<int> A(n + 5);
    for (int i = 0; i < m; ++i) {
        IO::read(val);
        ++A.at(val);
    }
    int min_val = numeric_limits<int>::max();
    for (int i = 1; i <= n; ++i) {
        min_val = min(min_val, A.at(i));
    }
    IO::writeln(min_val);


    return 0;
}

