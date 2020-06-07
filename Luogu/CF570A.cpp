#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define CODEFORCES

#ifdef CODEFORCES
namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = _getchar_nolock(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = _getchar_nolock();
        while (isdigit(c)) t = t * 10 + c - 48, c = _getchar_nolock();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, _putchar_nolock('-');
        if (x > 9) write(x / 10);
        _putchar_nolock(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        _putchar_nolock('\n');
    }
}
#else
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
#endif

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

int main() {

    int n, m;
    ll votes;
    IO::read(n, m);
    unordered_map<int, int, custom_hash> stats_among_cities;
    for (int i = 0; i < m; ++i) {
        unordered_map<int, ll, custom_hash> stats;
        for (int j = 1; j <= n; ++j) {
            IO::read(votes);
            stats[j] = votes;
        }
        ll max_elections = -1;
        for (const auto &[k, v] : stats) {
            max_elections = max(max_elections, v);
        }
        int smallest_id_with_max_elections = numeric_limits<int>::max();
        for (const auto &[k, v] : stats) {
            if (v == max_elections) {
                smallest_id_with_max_elections = min(smallest_id_with_max_elections, k);
            }
        }
        ++stats_among_cities[smallest_id_with_max_elections];
    }
    int max_cities = -1;
    for (const auto &[k, v] : stats_among_cities) {
        max_cities = max(max_cities, v);
    }
    int smallest_id_with_max_cities = numeric_limits<int>::max();
    for (const auto &[k, v] : stats_among_cities) {
        if (v == max_cities) {
            smallest_id_with_max_cities = min(smallest_id_with_max_cities, k);
        }
    }
    IO::writeln(smallest_id_with_max_cities);

    return 0;
}