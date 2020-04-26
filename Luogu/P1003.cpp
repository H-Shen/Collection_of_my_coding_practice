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

struct Rec {
    int x1, y1, x2, y2;
};

int main() {

    int n, a, b, g, k;
    IO::read(n);
    vector<Rec> A(n);
    for (int i = 0; i < n; ++i) {
        IO::read(a, b, g, k);
        A.at(i).x1 = a;
        A.at(i).y1 = b;
        A.at(i).x2 = a + g;
        A.at(i).y2 = b + k;
    }
    int x, y;
    IO::read(x, y);
    for (int i = n - 1; i >= 0; --i) {
        if (x >= A.at(i).x1 && x <= A.at(i).x2 && y >= A.at(i).y1 && y <= A.at(i).y2) {
            IO::writeln(i + 1);
            return 0;
        }
    }
    IO::writeln(-1);
    return 0;
}
