// https://open.kattis.com/problems/dvds
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        puts("");
    }
}

int main() {

    int t, n;
    IO::read(t);
    while (t--) {
        IO::read(n);
        vector<int> A(n);
        int operation = 1;
        for (auto &i : A) {
            IO::read(i);
            if (operation == i) {
                ++operation;
            }
        }
        IO::writeln(n + 1 - operation);
    }

    return 0;
}
