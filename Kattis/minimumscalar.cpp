// https://open.kattis.com/problems/minimumscalar
//
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

    int t, n;
    IO::read(t);
    for (int i = 1; i <= t; ++i) {
        IO::read(n);
        vector<ll> A(n);
        for (auto &j : A) IO::read(j);
        vector<ll> B(n);
        for (auto &j : B) IO::read(j);
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<>());
        ll s = 0;
        for (int j = 0; j < n; ++j) {
            s += A.at(j) * B.at(j);
        }
        fputs_unlocked("Case #", stdout);
        IO::write(i);
        fputs_unlocked(": ", stdout);
        IO::writeln(s);
    }
    return 0;
}
