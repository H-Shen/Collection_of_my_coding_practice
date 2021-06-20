// https://open.kattis.com/problems/bridgesandtunnels2

#include <bits/extc++.h>

using namespace std;
using ll = long long;

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

constexpr ll INF = 4e18;

struct Node {
    int v;
    ll w1, w2;  // w1: time spent outside w2: time spent
    Node() =default;
    Node(int v, ll w1, ll w2) : v(v), w1(w1), w2(w2) {}
};

int n, m, p, s, t;
ll c;
vector<vector<Node> > AL;
vector<ll> dist1, dist2;
vector<vector<pair<int,ll> > > spt;

void dijkstra() {
    fill(dist1.begin(),dist1.end(),INF);
    dist1[s] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<> > pq;
    pq.push({dist1[s],s});
    while (!pq.empty()) {
        ll d_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d_u != dist1[u]) continue;
        for (const auto &i : AL[u]) {
            int v = i.v;
            ll w = i.w1;
            if (dist1[u] + w < dist1[v]) {
                dist1[v] = dist1[u] + w;
                pq.push({dist1[v],v});
            }
        }
    }
}

void getSpt() {
    fill(spt.begin(),spt.end(),vector<pair<int,ll> >());
    for (int i = 0; i < n; ++i) {
        for (const auto &j : AL[i]) {
            if (dist1[i] + j.w1 == dist1[j.v]) {
                spt[i].emplace_back(j.v, j.w2);
            }
        }
    }
}

void dijkstra2() {
    fill(dist2.begin(),dist2.end(),INF);
    dist2[s] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<> > pq;
    pq.push({dist2[s],s});
    while (!pq.empty()) {
        ll d_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d_u != dist2[u]) continue;
        for (const auto &[v, w] : spt[u]) {
            if (dist2[u] + w < dist2[v]) {
                dist2[v] = dist2[u] + w;
                pq.push({dist2[v],v});
            }
        }
    }
}

int main() {
    IO::read(n, m, p);
    AL.resize(n);
    dist1.resize(n);
    dist2.resize(n);
    spt.resize(n);
    char ch;
    int u, v;
    while (m--) {
        IO::read(u,v,c);
        scanf(" %c", &ch);
        if (ch == 'I') {
            AL[u].emplace_back(Node(v, 0, c));
            AL[v].emplace_back(Node(u, 0, c));
        }
        else {
            AL[u].emplace_back(Node(v, c, c));
            AL[v].emplace_back(Node(u, c, c));
        }
    }
    while (p--) {
        IO::read(s,t);
        dijkstra();
        if (dist1[t] == INF) {
            printf("IMPOSSIBLE\n");
        }
        else {
            getSpt();
            dijkstra2();
            IO::write(dist1[t]);
            putchar_unlocked(' ');
            IO::writeln(dist2[t]);
        }
    }
    return 0;
}
