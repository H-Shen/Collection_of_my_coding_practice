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

int main() {

    int n, s, a, b, x, y;
    IO::read(n, s, a, b);
    int max_height = a + b;
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        IO::read(x, y);
        if (x <= max_height) {
            A.emplace_back(y);
        }
    }
    sort(A.begin(), A.end());
    int counter = 0;
    for (const auto &i : A) {
        s -= i;
        if (s < 0) {
            break;
        }
        ++counter;
    }
    IO::writeln(counter);

    return 0;
}