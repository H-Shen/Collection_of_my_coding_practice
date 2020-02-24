// https://www.nowcoder.com/practice/16212f7d46e44174b5505997ea998538

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
    Edge() = default;
};


int main() {

    int n, m, u, v, w, cond;
    while (~scanf("%d", &n) && n != 0) {
        m = n * (n - 1) / 2;
        DSU::init(n);
        vector<Edge> A(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d %d", &u, &v, &w, &cond);
            if (cond == 1) {
                DSU::merge(u, v);
            }
            A.at(i) = Edge(u, v, w);
        }
        sort(A.begin(), A.end(), [](const Edge &lhs, const Edge &rhs){
            return (lhs.w < rhs.w);
        });
        vector<Edge> MST;
        for (const auto &i : A) {
            if (!DSU::is_same_group(i.v, i.u)) {
                DSU::merge(i.u, i.v);
                MST.emplace_back(i);
            }
        }
        int cost = 0;
        for (const auto &i : MST) {
            cost += i.w;
        }
        printf("%d\n", cost);
    }

    return 0;
}