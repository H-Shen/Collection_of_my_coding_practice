#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

int main() {

    ll min_cost = 0;
    ll most_earn = 0;
    int n, m;
    IO::read(n, m);
    vector<ll> A(m);
    for (auto &i : A) IO::read(i);
    sort(A.begin(), A.end());
    for (int i = m - 1; i >= 0; --i) {
        if (most_earn < (m - i) * A.at(i)) {
            min_cost = A.at(i);
            most_earn = (m - i) * A.at(i);
        }
    }
    IO::write(min_cost);
    putchar_unlocked(' ');
    IO::writeln(most_earn);
    return 0;
}
