// Diameter of a tree with every edge weights 1
//
#include <bits/stdc++.h>

using namespace std;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

// Twice DFS
namespace TreeDiameter {
    vector<vector<int> > adj;
    vector<int> d;
    int c = 0;
    void dfs(int u) {
        for (const auto &v : adj.at(u)) {
            if (d.at(v) == 0) {
                d.at(v) = d.at(u) + 1;
                if (d.at(v) > d.at(c)) {
                    c = v;
                }
                dfs(v);
            }
        }
    }
    int diameter() {
        d.at(0) = 1;    // node id starts from 0
        dfs(0);
        fill(d.begin(), d.end(), 0);
        d.at(c) = 1;
        dfs(c);
        return d.at(c) - 1;
    }
    void init(int n) {
        adj.resize(n + 5);
        d.resize(n + 5);
    }
}

int main() {

    int n, u, v;
    IO::read(n);
    TreeDiameter::init(n);
    for (int i = 0; i < n - 1; ++i) {
        IO::read(u, v);
        --u;
        --v;
        TreeDiameter::adj.at(u).emplace_back(v);
        TreeDiameter::adj.at(v).emplace_back(u);
    }
    IO::writeln(TreeDiameter::diameter());


    return 0;
}
