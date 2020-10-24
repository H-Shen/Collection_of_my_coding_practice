// https://open.kattis.com/problems/buttonbashing
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using int128 = __int128;
using pii = pair<int, int>;

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

vector<int> steps;
unordered_map<int, int, custom_hash> vis;
int e, target;

void bfs(int u) {
    vis[u] = 0;
    queue<int> q;
    q.push(u);
    int new_u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (const auto &i : steps) {
            new_u = i + u;
            if (new_u < 0) {
                new_u = 0;
            }
            if (new_u > 3600) {
                new_u = 3600;
            }
            if (vis.find(new_u) == vis.end() || vis[new_u] > vis[u] + 1) {
                vis[new_u] = vis[u] + 1;
                q.push(new_u);
            }
        }
    }
}

int main() {

    int t;
    IO::read(t);
    while (t--) {
        IO::read(e, target);
        steps.resize(e);
        for (auto &i : steps) {
            IO::read(i);
        }
        bfs(0);
        map<int, int> m(vis.begin(), vis.end());
        auto iter = m.lower_bound(target);
        cout << iter->second << ' ' << iter->first - target << '\n';
        // reset
        vector<int>().swap(steps);
        vis.clear();
    }
    return 0;
}
