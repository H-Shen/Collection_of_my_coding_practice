#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 10007;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
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

constexpr int MAXN = 2000005;
bitset<MAXN> A;

int main() {

    int n;
    double a;
    int t;
    IO::read(n);
    while (n--) {
        scanf("%lf", &a);
        IO::read(t);
        for (int i = 1; i <= t; ++i) {
            A.flip(static_cast<int>(i * a));
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        if (A[i]) {
            IO::writeln(i);
            return 0;
        }
    }

    return 0;
}
