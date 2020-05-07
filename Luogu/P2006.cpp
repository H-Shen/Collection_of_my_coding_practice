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

int k, m;
ll n;
__int128 k_128;
__int128 temp;

int main() {

    IO::read(k, m, n);
    k_128 = k;
    vector<ll> a(m);
    vector<ll> b(m);
    for (int i = 0; i < m; ++i) {
        IO::read(a.at(i), b.at(i));
    }
    bool have_ans = false;
    bool first_item = true;
    for (int i = 0; i < m; ++i) {
        if (b.at(i) <= 0) {
            if (n == 0) {
                have_ans = true;
                if (first_item) {
                    first_item = false;
                } else {
                    putchar_unlocked(' ');
                }
                IO::write(i + 1);
            }
        }
        else if (a.at(i) <= 0) {
            have_ans = true;
            if (first_item) {
                first_item = false;
            } else {
                putchar_unlocked(' ');
            }
            IO::write(i + 1);
        }
        else {
            if (n % b.at(i) == 0) {
                temp = n / b.at(i) * a.at(i);
                if (temp <= k_128) {
                    have_ans = true;
                    if (first_item) {
                        first_item = false;
                    } else {
                        putchar_unlocked(' ');
                    }
                    IO::write(i + 1);
                }
            } else {
                temp = (n / b.at(i) + 1) * a.at(i);
                if (temp <= k_128) {
                    have_ans = true;
                    if (first_item) {
                        first_item = false;
                    } else {
                        putchar_unlocked(' ');
                    }
                    IO::write(i + 1);
                }
            }
        }
    }
    if (!have_ans) {
        IO::writeln(-1);
    } else {
        putchar_unlocked('\n');
    }

    return 0;
}
