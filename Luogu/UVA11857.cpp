#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

// The collection of methods and data structures for Kruskal's algorithm
namespace Kruskal {
    struct Edge {
        int u, v;
        ll w;
        Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &lhs, const Edge &rhs) {
        return (lhs.w < rhs.w);
    }
    ll init(vector<Edge> &E, int number_of_nodes) {
        // init a DSU
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        ll max_cost = -1;
        for (const auto &i : E) {
            if (!DSU::is_same_group(i.u, i.v)) {
                DSU::merge(i.u, i.v);
                max_cost = max(max_cost, i.w);
            }
        }
        return max_cost;
    }
}

int main() {

    int n, m;
    while (true) {
        IO::read(n, m);
        if (n == 0 && m == 0) break;
        vector<Kruskal::Edge> A(m);
        int random_city = 0;
        for (int i = 0; i < m; ++i) {
            IO::read(A.at(i).u, A.at(i).v, A.at(i).w);
            random_city = A.at(i).u;
        }
        auto result = Kruskal::init(A, n);
        if (DSU::Size[DSU::find(random_city)] != n) {
            puts("IMPOSSIBLE");
        } else {
            IO::writeln(result);
        }
    }
    return 0;
}