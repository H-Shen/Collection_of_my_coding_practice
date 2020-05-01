// https://open.kattis.com/problems/hydrasheads
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll INF = 0x3f3f3f3f;

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

struct my_hash_func {
    size_t operator ()(const pair<ll, ll> &obj) const {
        return hash<ll>()(obj.first) ^ hash<ll>()(obj.second);
    }
};
unordered_map<pair<ll, ll>, ll, my_hash_func> A;

ll dfs(ll h, ll t) {
    // Case 1:
    pair<ll, ll> temp_pair = make_pair(h, t);
    if (A.find(temp_pair) != A.end()) {
        return A[temp_pair];
    }
    ll minimal_moves = INF;
    // Case 2:
    if (h >= 2) {
        minimal_moves = min(minimal_moves, dfs(h - 2, t));
    }
    // Case 3:
    if (t >= 2) {
        minimal_moves = min(minimal_moves, dfs(h + 1, t - 2));
    }
    // Case 4:
    if (h <= 2 && t <= 2) {
        minimal_moves = min(minimal_moves, dfs(h, t + 1));
    }
    ++minimal_moves;
    A[temp_pair] = minimal_moves;
    return minimal_moves;
}

int main() {

    // pre
    A[make_pair(1L, 0L)] = INF;
    A[make_pair(0L, 0L)] = 0;
    A[make_pair(2L, 0L)] = 1;
    A[make_pair(1L, 2L)] = 2;
    A[make_pair(0L, 4L)] = 3;

    ll h, t, minimal_moves;
    while (true) {
        IO::read(h, t);
        if (h == 0 && t == 0) {
            break;
        }
        minimal_moves = dfs(h, t);
        if (minimal_moves == INF) {
            IO::writeln(-1);
        } else {
            IO::writeln(minimal_moves);
        }
    }
    return 0;
}
