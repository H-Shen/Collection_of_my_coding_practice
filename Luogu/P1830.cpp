#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 105;

struct Node {
    int val;
    int round;
};

Node A[MAXN][MAXN];

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

    int n, m, x, y, x1, x2, y1, y2;
    IO::read(n, m, x, y);
    for (int round = 1; round <= x; ++round) {
        IO::read(x1, y1, x2, y2);
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                ++A[j][i].val;
                A[j][i].round = round;
            }
        }
    }
    while (y--) {
        IO::read(x1, y1);
        if (A[y1][x1].val == 0) {
            putchar_unlocked('N');
        } else {
            putchar_unlocked('Y');
            putchar_unlocked(' ');
            IO::write(A[y1][x1].val);
            putchar_unlocked(' ');
            IO::write(A[y1][x1].round);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
