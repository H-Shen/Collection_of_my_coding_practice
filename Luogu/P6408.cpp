#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 5;

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

    int winnerNumber = -1;
    int maxVal = -1;
    int a, b, c, d, sum;

    for (int i = 0; i < MAXN; ++i) {
        IO::read(a, b, c, d);
        sum = a + b + c + d;
        if (sum > maxVal) {
            maxVal = sum;
            winnerNumber = i + 1;
        }
    }
    IO::write(winnerNumber);
    putchar_unlocked(' ');
    IO::writeln(maxVal);
    return 0;
}
