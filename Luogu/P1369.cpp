#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace IO {
    template<typename T>
    inline void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

constexpr int MAXN = 105;
int A[MAXN][MAXN];

auto solve(int i, int j, int i_, int j_) {
    if (i >= i_ && j >= j_) {
        return 0;
    }
    return A[i_][j_] + A[i - 1][j - 1] - A[i_][j - 1] - A[i - 1][j_];
}

int main() {

    int n, x, y;
    int x_max = 0;
    int y_max = 0;
    IO::read(n);
    while (n--) {
        IO::read(x, y);
        x_max = max(x, x_max);
        y_max = max(y, y_max);
        A[x][y] = 1;
    }
    for (int i = 1; i <= x_max; ++i) {
        for (int j = 1; j <= y_max; ++j) {
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }
    int counter = 0;
    for (int i = 1; i <= x_max; ++i) {
        for (int j = 1; j <= y_max; ++j) {
            for (int i_ = 2; i_ <= x_max; ++i_) {
                for (int j_ = 2; j_ <= y_max; ++j_) {
                    if (!(i >= i_ || j >= j_)) {
                        counter = max(counter, solve(i, j, i_, j_) -
                                               solve(i + 1, j + 1, i_ - 1,
                                                     j_ - 1));
                    }
                }
            }
        }
    }
    IO::writeln(counter);

    return 0;
}