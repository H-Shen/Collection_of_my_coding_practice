// https://open.kattis.com/problems/cakeymccakeface
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<ll, int, custom_hash> stats;

int main(int argc, char *argv[]) {

    int n, m;
    ll diff;
    IO::read(n, m);
    vector<ll> A(n);
    for (auto &i : A) IO::read(i);
    vector<ll> B(m);
    for (auto &i : B) IO::read(i);
    for (const auto &i : A) {
        for (const auto &j : B) {
            diff = j - i;
            if (diff >= 0) {
                ++stats[diff];
            }
        }
    }
    // handle the corner case
    if (stats.empty()) {
        IO::writeln(0);
        return 0;
    }
    int max_freq = numeric_limits<int>::min();
    for (const auto &[k, v] : stats) {
        max_freq = max(max_freq, v);
    }
    ll cooking_time = numeric_limits<ll>::max();
    for (const auto &[k, v] : stats) {
        if (v == max_freq && cooking_time > k) {
            cooking_time = k;
        }
    }
    IO::writeln(cooking_time);

    return 0;
}
