#include <bits/extc++.h>

using namespace std;
using ll = long long;

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
        if (x != father[x]) {
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

namespace Kruskal {
    struct Edge {
        int u, v, w;
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &l, const Edge &r) {
        return (l.w < r.w);
    }
    int init(vector<Edge> &E, int number_of_nodes) {
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        int max_length = numeric_limits<int>::min();
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                max_length = max(max_length, w);
            }
        }
        return max_length;
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<Kruskal::Edge> E(m);
    for (auto &i : E) {
        scanf("%d %d %d", &i.u, &i.v, &i.w);
    }
    printf("%d\n", Kruskal::init(E, n));
    
    return 0;
}
