#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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

constexpr double EPS = 1e-7;
inline
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {
    int l, d, x;
    IO::read(l, d, x);
    
    int maxVal = -1;
    int minVal = 10005;
    int sum;

    for (int i = l, i_copy; i <= d; ++i) {
        sum = 0;
        i_copy = i;
        while (i_copy > 0) {
            sum += i_copy % 10;
            i_copy /= 10;
        }
        if (sum == x) {
            if (i > maxVal) {
                maxVal = i;
            }
            if (i < minVal) {
                minVal = i;
            }
        }
    }
    IO::writeln(minVal);
    IO::writeln(maxVal);
    return 0;
}