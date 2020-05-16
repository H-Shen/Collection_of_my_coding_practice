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

ll exgcd(ll a, ll b, ll &x, ll &y) {

    // Case 1:
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // Case 2:
    long long gcdVal = exgcd(b, a % b, x, y);
    long long temp = x;
    x = y;
    y = temp - a / b * y;
    return gcdVal;
}

int main() {

    ll a, b, x0, y0;
    ll c = 1;
    IO::read(a, b);
    ll gcdVal = exgcd(a, b, x0, y0);
    x0 = x0 / gcdVal * c;
    ll t = b / gcdVal;
    x0 = (x0 % t + t) % t;
    IO::writeln(x0);

    return 0;
}
