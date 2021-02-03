// https://open.kattis.com/problems/floorplan

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
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

ll n, a, b, m, k, a_, b_;

int main() {

    IO::read(n);
    ll upper = (ll)sqrt(n * 1.0) + 1;
    for (a = 1; a <= upper; ++a) {
        if (n % a == 0) {
            b = n / a;
            a_ = a;
            b_ = b;
            if (a_ > b_) swap(a_, b_);
            if ((a_ + b_) % 2 == 0 && (b_ - a_) % 2 == 0) {
                m = (a_ + b_) / 2;
                k = (b_ - a_) / 2;
                cout << m << ' ' << k << '\n';
                return 0;
            }
        }
    }
    cout << "impossible" << '\n';

    return 0;
}
