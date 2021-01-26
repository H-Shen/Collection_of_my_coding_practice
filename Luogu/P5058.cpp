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

int a, b;
int answer = 0x3f3f3f3f;

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
    bool f(int v) {
        if (dfsNum[v] <= dfsNum[a] && dfsNum[v] > dfsNum[b]) return true;
        if (dfsNum[v] <= dfsNum[b] && dfsNum[v] > dfsNum[a]) return true;
        return false;
    }
    void Tarjan(int u, int father_of_u) {
        vis[u] = true;
        dfsLow[u] = dfsNum[u] = ++timestamp;    // tag timestamp
        for (const auto &v : adj[u]) {
            if (!vis[v]) {
                Tarjan(v, u);
                dfsLow[u] = min(dfsLow[u], dfsLow[v]);
                if (dfsLow[v] >= dfsNum[u] && !isArticulationPoint[u]) {
                    isArticulationPoint[u] = true;
                    // special process here
                    if (u != a && u != b && f(v)) {
                        answer = min(answer, u);
                    }
                }
            } else if (v != father_of_u) {
                dfsLow[u] = min(dfsLow[u], dfsNum[v]);
            }
        }
    }
}

int main() {

    int n, u, v;
    IO::read(n);
    ArticulationPoint::init(n);
    while (true) {
        IO::read(u, v);
        if (u == 0 && v == 0) break;
        ArticulationPoint::adj[u].emplace_back(v);
        ArticulationPoint::adj[v].emplace_back(u);
    }
    IO::read(a, b);

    // Usage:
    for (int i = 1; i <= n; ++i) {
        if (!ArticulationPoint::vis[i]) {
            ArticulationPoint::timestamp = 0;   // reset the timestamp
            ArticulationPoint::Tarjan(i, i);
        }
    }
    if (answer == 0x3f3f3f3f) {
        puts("No solution");
    } else {
        IO::writeln(answer);
    }
    return 0;
}