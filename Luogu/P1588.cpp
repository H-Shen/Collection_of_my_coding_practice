#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
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

int x, y;
gp_hash_table<int, int, custom_hash> vis;
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 0;
    int new_u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        // Method 1:
        new_u = u - 1;
        if (new_u >= 0) {
            if (vis.find(new_u) == vis.end()) {
                vis[new_u] = vis[u] + 1;
                q.push(new_u);
            } else if (vis[new_u] > vis[u] + 1) {
                vis[new_u] = vis[u] + 1;
                q.push(new_u);
            }
        }
        // Method 2:
        if (u < y) {
            new_u = u + 1;
            if (new_u >= 0) {
                if (vis.find(new_u) == vis.end()) {
                    vis[new_u] = vis[u] + 1;
                    q.push(new_u);
                } else if (vis[new_u] > vis[u] + 1) {
                    vis[new_u] = vis[u] + 1;
                    q.push(new_u);
                }
            }
        }
        // Method 3:
        if (u < y) {
            new_u = u * 2;
            if (new_u >= 0) {
                if (vis.find(new_u) == vis.end()) {
                    vis[new_u] = vis[u] + 1;
                    q.push(new_u);
                } else if (vis[new_u] > vis[u] + 1) {
                    vis[new_u] = vis[u] + 1;
                    q.push(new_u);
                }
            }
        }
    }
}

int main() {

    int t;
    IO::read(t);
    while (t--) {
        IO::read(x, y);
        bfs(x);
        IO::writeln(vis[y]);
        vis.clear();
    }

    return 0;
}