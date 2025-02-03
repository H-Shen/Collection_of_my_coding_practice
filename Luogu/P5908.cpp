#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

namespace IO {
    template<typename T>
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
    template<typename T>
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template<typename T, typename... Args>
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }
    template<typename T>
    void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template<typename T>
    void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

vector<vector<int>> adj;
int n, d;

int dijkstra() {
    vector<int> dist(n+1, INF);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.emplace(dist[1], 1);
    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        int dis = p.first;
        int u = p.second;
        pq.pop();
        if (dis != dist[u]) {
            continue;
        }
        for (const auto &v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pq.emplace(dist[v], v);
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (dist[i] <= d) {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    IO::read(n, d);
    adj.resize(n+1);
    int u, v;
    for (int i = 1; i <= n-1; ++i) {
        IO::read(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    IO::writeln(dijkstra());
    return 0;
}
