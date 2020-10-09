// https://open.kattis.com/problems/pikemaneasy
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 1000000007;

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

    int n;
    ll t, a, b, c, t_0;
    IO::read(n, t, a, b, c, t_0);
    vector<ll> time(n);
    time.at(0) = t_0;
    for (int i = 1; i < n; ++i) {
        time.at(i) = (a * time.at(i - 1) + b) % c + 1;
    }
    ll penalty = 0;
    int counter = 0;
    sort(time.begin(), time.end());
    vector<ll> time_prefix_sum(n);
    partial_sum(time.begin(), time.end(), time_prefix_sum.begin());
    ll total_time = 0;

    for (int i = 0; i < n; ++i) {
        if (total_time + time.at(i) > t) {
            break;
        }
        ++counter;
        penalty = (penalty + time_prefix_sum.at(i)) % MOD;
        total_time += time.at(i);
    }
    IO::write(counter);
    putchar_unlocked(' ');
    IO::writeln(penalty % MOD);
    return 0;
}
