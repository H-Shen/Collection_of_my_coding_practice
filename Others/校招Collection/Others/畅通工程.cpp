// https://www.nowcoder.com/practice/23c9fe571c1346bb91fdffea8a0b195f

#include <bits/stdc++.h>

using namespace std;

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
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct my_hash_func {
    size_t operator ()(const pair<int, int> &obj) const {
        return hash<int>()(obj.first) ^ hash<int>()(obj.second);
    }
};

int main() {

    int n, m, u, v, w;
    while (~scanf("%d", &n)) {
        if (n == 0) {
            break;
        }
        scanf("%d", &m);
        DSU::init(m);
        unordered_map<pair<int, int>, int, my_hash_func> filter;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            if (u > v) {
                swap(u, v);
            }
            auto temp_pair = make_pair(u, v);
            if (filter.find(temp_pair) == filter.end()) {
                filter[temp_pair] = w;
            } else {
                filter[temp_pair] = min(w, filter[temp_pair]);
            }
        }
        vector<Edge> A;
        for (const auto &i : filter) {
            A.emplace_back(Edge(i.first.first, i.first.second, i.second));
        }
        sort(A.begin(), A.end(), [](const Edge &lhs, const Edge &rhs) {
            return (lhs.w < rhs.w);
        });
        vector<Edge> MST;
        for (const auto &i : A) {
            if (!DSU::is_same_group(i.u, i.v)) {
                DSU::merge(i.u, i.v);
                MST.emplace_back(i);
            }
        }
        unordered_set<int> temp_unset;
        int cost = 0;
        for (const auto &i : MST) {
            temp_unset.insert(i.u);
            temp_unset.insert(i.v);
            cost += i.w;
        }
        if (static_cast<int>(temp_unset.size()) != m) {
            printf("?\n");
        } else {
            printf("%d\n", cost);
        }
    }
    return 0;
}
