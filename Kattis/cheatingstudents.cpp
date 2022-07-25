// https://open.kattis.com/problems/cheatingstudents

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
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
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
    bool is_same_group(int u,int v) {
        return find(u) == find(v);
    }
}

struct Edge final {
    int u,v;
    ll w;
    Edge() = default;
    Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
};

int n;
vector<pair<int,int>> vec;
vector<Edge> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vec.resize(n);
    for (auto&i : vec) {
        cin >> i.first >> i.second;
    }
    edges.resize(n*(n-1)/2);
    for (int i = 0, k = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j, ++k) {
            edges[k].u = i;
            edges[k].v = j;
            edges[k].w = abs(vec[i].first-vec[j].first)+abs(vec[i].second-vec[j].second);
        }
    }
    sort(edges.begin(),edges.end(),[](const Edge &l, const Edge &r){
        return l.w < r.w;
    });
    ll total_weights = 0;
    DSU::init(n);
    for (const auto &i : edges) {
        if (!DSU::is_same_group(i.u, i.v)) {
            DSU::merge(i.u, i.v);
            total_weights += i.w;
        }
    }
    cout << total_weights * 2 << '\n';
    return 0;
}
