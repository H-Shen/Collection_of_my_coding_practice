// https://open.kattis.com/problems/curveknights

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

constexpr int MAXN = 60;

int n, m, u, v;
ll w;
vector<ll> needs;
vector<unordered_set<int> > inDegree;
vector<vector<pair<int, ll> > > AL;
bitset<MAXN> vis;

int main() {

    IO::read(n, m);
    inDegree.resize(n);
    AL.resize(n);
    needs.resize(n);

    for (auto &i : needs) IO::read(i);
    for (int i = 0; i < m; ++i) {
        IO::read(v, u, w);
        AL[u].emplace_back(v, w);
        inDegree[v].insert(u);
    }
    queue<int> q;
    // update q with nodes with no incoming degrees
    for (int i = 0; i < n; ++i) {
        if (inDegree[i].empty() && !vis[i]) {
            q.push(i);
            vis[i] = true;
        }
    }
    while (!q.empty()) {
        int u_ = q.front();
        q.pop();
        for (const auto &[v_, w_] : AL[u_]) {
            needs[v_] += w_ * needs[u_];
        }
        // remove u_ from inDegree
        for (auto &i : inDegree) {
            i.erase(u_);
        }
        // update inDegree
        for (int i = 0; i < n; ++i) {
            if (inDegree[i].empty() && !vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    for (const auto &i : needs) {
        IO::write(i);
        putchar_unlocked(' ');
    }
    putchar_unlocked('\n');

    return 0;
}
