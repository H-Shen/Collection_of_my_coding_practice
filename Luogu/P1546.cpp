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

int main() {

    int N, u, v, w;
    scanf("%d", &N);
    // init a DSU
    DSU::init(N);
    vector<Edge> A;
    unordered_map<pair<int, int>, int, my_hash_func> temp_unmap;
    pair<int, int> temp_pair;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &w);
            if (i == j) {
                continue;
            }
            u = i;
            v = j;
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
    int cost = 0;
    for (const auto &[u, v, w] : E_filter) {
        if (!DSU::is_same_group(u, v)) {
            DSU::merge(u, v);
            cost += w;
        }
    }
    printf("%d\n", cost);

    return 0;
}
