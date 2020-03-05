// https://open.kattis.com/problems/firetrucksarered
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int c = getchar();
        t = 0;
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    }
    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }
    template<typename T>
    inline void write(T x) {
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template<typename T>
    inline void writeln(T x) {
        write(x);
        puts("");
    }
}

namespace DSU {
    vector<int> father;
    vector<int> Size;
    inline
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    inline
    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    inline
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace Kruskal {
    struct Edge {
        int u, v, w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };
    bool cmp(const Edge &l, const Edge &r) {
        return l.w < r.w;
    }
    vector<Edge> init(vector<Edge> A, int number_of_nodes) {
        DSU::init(number_of_nodes);
        sort(A.begin(), A.end(), cmp);
        vector<Edge> result;
        for (const auto &i : A) {
            if (!DSU::is_same_group(i.u, i.v)) {
                DSU::merge(i.u, i.v);
                result.emplace_back(i);
            }
        }
        return result;
    }
}

int main() {

    int n, m, d;
    IO::read(n);
    unordered_map<int, unordered_set<int> > G;
    for (int i = 1; i <= n; ++i) {
        IO::read(m);
        while (m--) {
            IO::read(d);
            G[d].insert(i);
        }
    }
    vector<Kruskal::Edge> A;
    for (const auto &[weight, edges] : G) {
        if (edges.size() > 1) {
            vector<int> temp_vec(edges.begin(), edges.end());
            for (size_t i = 1; i != temp_vec.size(); ++i) {
                A.emplace_back(Kruskal::Edge(temp_vec.at(i - 1), temp_vec.at(i), weight));
            }
        }
    }
    auto result = Kruskal::init(A, n);
    if (DSU::Size[DSU::find(1)] != n) {
        printf("impossible\n");
    } else {
        for (const auto &[u, v, w] : result) {
            printf("%d %d %d\n", u, v, w);
        }
    }

    return 0;
}
