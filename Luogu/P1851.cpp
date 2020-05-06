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

constexpr int MAXN = 100005;
vector<int> SOF(MAXN);

void pre() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; i * j < MAXN; ++j) {
            SOF.at(i * j) += i;
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        SOF.at(i) -= i;
    }
}

int main() {

    pre();
    int s, a, b;
    IO::read(s);
    for (a = s;; ++a) {
        b = SOF.at(a);
        if (SOF.at(b) == a && a != b) {
            IO::write(a);
            putchar_unlocked(' ');
            IO::writeln(b);
            break;
        }
    }

    return 0;
}
