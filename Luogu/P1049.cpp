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

    int v, n;
    IO::read(v, n);
    vector<int> A(n);
    vector<int> dp(v + 5);
    for (auto &i : A) IO::read(i);
    for (int i = 0; i < n; ++i) {
        for (int j = v; j >= A.at(i); --j) {
            dp.at(j) = max(dp.at(j), dp.at(j - A.at(i)) + A.at(i));
        }
    }
    IO::writeln(v - dp.at(v));

    return 0;
}