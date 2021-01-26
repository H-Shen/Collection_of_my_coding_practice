#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

// Obtain Articulation Points in an undirected graph by Tarjan
namespace ArticulationPoint {
    vector<vector<int> > adj;
    vector<int> dfsNum, dfsLow;
    int timestamp;
    vector<bool> isArticulationPoint, vis;
    void init(int n) {
        adj.resize(n + 5);
        dfsNum.resize(n + 5);
        dfsLow.resize(n + 5);
        isArticulationPoint.resize(n + 5, false);
        vis.resize(n + 5, false);
        timestamp = 0;
    }
    void Tarjan(int u, int father_of_u) {
        vis[u] = true;
        dfsLow[u] = dfsNum[u] = ++timestamp;    // tag timestamp
        int child_of_u = 0;
        for (const auto &v : adj[u]) {
            if (!vis[v]) {
                ++child_of_u;
                Tarjan(v, u);
                dfsLow[u] = min(dfsLow[u], dfsLow[v]);
                if (father_of_u != u && dfsLow[v] >= dfsNum[u] && !isArticulationPoint[u]) {
                    isArticulationPoint[u] = true;
                }
            } else if (v != father_of_u) {
                dfsLow[u] = min(dfsLow[u], dfsNum[v]);
            }
        }
        if (father_of_u == u && child_of_u > 1 && !isArticulationPoint[u]) {
            isArticulationPoint[u] = true;
        }
    }
}

int main() {

    int n, m, u, v;
    IO::read(n, m);
    ArticulationPoint::init(n);
    while (m--) {
        IO::read(u, v);
        ArticulationPoint::adj[u].emplace_back(v);
        ArticulationPoint::adj[v].emplace_back(u);
    }

    // Usage:
    for (int i = 1; i <= n; ++i) {
        if (!ArticulationPoint::vis[i]) {
            ArticulationPoint::timestamp = 0;   // reset the timestamp
            ArticulationPoint::Tarjan(i, i);
        }
    }
    vector<int> output;
    for (int i = 1; i <= n; ++i) {
        if (ArticulationPoint::isArticulationPoint[i]) {
            output.emplace_back(i);
        }
    }
    IO::writeln(output.size());
    sort(output.begin(), output.end());
    for (const auto &i : output) {
        IO::write(i);
        putchar_unlocked(' ');
    }
    return 0;
}
