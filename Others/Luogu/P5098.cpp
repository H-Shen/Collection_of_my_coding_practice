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

// abs(x0-x1) + abs(y0-y1)
// Case 1: x0-x1 >= 0
// Subcase 1: x0-x1+y0-y1=(x0+y0)-(x1+y1)
// Subcase 2: x0-x1+y1-y0=(x0-y0)-(x1-y1)
// Case 2: x0-x1 < 0
// Subcase 1: x1-x0+y0-y1=(x1-y1)-(x0-y0)
// Subcase 2: x1-x0+y1-y0=(x1+y1)-(x0+y0)
// Thus manhattan_max_dist = max( max(x+y) - min(x+y), max(x-y) - min(x-y) )

int main() {

    int N;
    IO::read(N);
    ll max_of_x_add_y = numeric_limits<ll>::min();
    ll min_of_x_add_y = numeric_limits<ll>::max();
    ll max_of_x_sub_y = numeric_limits<ll>::min();
    ll min_of_x_sub_y = numeric_limits<ll>::max();
    ll x, y;
    while (N--) {
        IO::read(x, y);
        max_of_x_add_y = max(max_of_x_add_y, x + y);
        min_of_x_add_y = min(min_of_x_add_y, x + y);
        max_of_x_sub_y = max(max_of_x_sub_y, x - y);
        min_of_x_sub_y = min(min_of_x_sub_y, x - y);
    }
    IO::writeln(max(max_of_x_add_y - min_of_x_add_y, max_of_x_sub_y - min_of_x_sub_y));


    return 0;
}
