// https://open.kattis.com/problems/eulerian2

#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

int n, m, w, u, v;
vector<unordered_map<int,int>> adj;
vector<int> path;

int main() {
    IO::read(n, m);
    adj.resize(n+1);
    for (int i = 0; i < m; ++i) {
        IO::read(u,v);
        ++adj[u][v];
    }
    IO::read(w);
    path.resize(w+1);
    for (auto &i : path) {
        IO::read(i);
    }
    for (int i = 0; i < w; ++i) {
        u = path[i];
        v = path[i+1];
        auto iter = adj[u].find(v);
        if (iter != adj[u].end()) {
            --iter->second;
            if (iter->second == 0) {
                adj[u].erase(v);
            }
        } else {
            IO::writeln(i+1);
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!adj[i].empty()) {
            puts("too short");
            return 0;
        }
    }
    puts("correct");
    return 0;
}
