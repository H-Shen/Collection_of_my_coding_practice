#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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
        int w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &lhs, const Edge &rhs) {
        return (lhs.w < rhs.w);
    }
    struct my_hash_func {
        size_t operator ()(const pair<int, int> &obj) const {
            return hash<int>()(obj.first) ^ hash<int>()(obj.second);
        }
    };
    vector<Edge> init(const vector<Edge> &E, int number_of_nodes) {
        // init a DSU
        DSU::init(number_of_nodes);
        // We use a hashmap to store the minimal weight between a pair of nodes
        unordered_map<pair<int, int>, int, my_hash_func> temp_unmap;
        pair<int, int> temp_pair;
        for (const auto &[u, v, w] : E) {
            if (u > v) {
                temp_pair.first = v;
                temp_pair.second = u;
            } else {
                temp_pair.first = u;
                temp_pair.second = v;
            }
            if (temp_unmap.find(temp_pair) == temp_unmap.end()) {
                temp_unmap[temp_pair] = w;
            } else {
                temp_unmap[temp_pair] = min(w, temp_unmap[temp_pair]);
            }
        }
        vector<Edge> E_filter(temp_unmap.size());
        int index = 0;
        for (const auto &[nodes, w] : temp_unmap) {
            E_filter.at(index).u = nodes.first;
            E_filter.at(index).v = nodes.second;
            E_filter.at(index).w = w;
            ++index;
        }
        sort(E_filter.begin(), E_filter.end(), cmp);
        vector<Edge> MST;
        for (const auto &[u, v, w] : E_filter) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                MST.emplace_back(Edge(u, v, w));
            }
        }
        return MST;
    }
}


int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<Kruskal::Edge> A(m);
    for (auto &[u, v, w] : A) {
        scanf("%d %d %d", &u, &v, &w);
    }
    auto result = Kruskal::init(A, n);

    int maximal_weight = -1;
    for (const auto &[u, v, w] : result) {
        maximal_weight = max(maximal_weight, w);
    }
    printf("%zu %d\n", result.size(), maximal_weight);
    return 0;
}
