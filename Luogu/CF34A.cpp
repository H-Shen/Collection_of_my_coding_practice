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

    int n;
    IO::read(n);
    vector<int> A(n);
    for (auto &i : A) IO::read(i);
    int min_dist = numeric_limits<int>::max();
    for (int i = 1; i < n; ++i) {
        min_dist = min(min_dist, abs(A.at(i) - A.at(i - 1)));
    }
    min_dist = min(min_dist, abs(A.at(0) - A.at(n - 1)));
    for (int i = 1; i < n; ++i) {
        if (abs(A.at(i) - A.at(i - 1)) == min_dist) {
            IO::write(i + 1);
            putchar(' ');
            IO::writeln(i);
            return 0;
        }
    }
    IO::write(1);
    putchar(' ');
    IO::writeln(n);
    return 0;
}
