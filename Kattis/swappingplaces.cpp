#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

namespace DSU {
    vector<int> father, Size;
    int cc;
    void init(int n) {
        father.resize(n);
        iota(father.begin(), father.end(), 0);
        Size.assign(n, 1);
        cc = n;
    }
    int find(int x) {
        return father[x] == x ? x : father[x] = find(father[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        father[x] = y;
        Size[y] += Size[x];
        --cc;
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace LCA1 {
    int n, LOG, dfn;
    vector<int> dfsIn, dfsOut;
    vector<vector<int>> AL, fa;

    void pre(int _n) {
        n = _n;
        LOG = max(1, static_cast<int>(ceil(log2(n))));
        dfn = 0;
        dfsIn.assign(n, 0);
        dfsOut.assign(n, 0);
        AL.assign(n, {});
        fa.assign(n, vector<int>(LOG+1, 0));
    }

    bool isAncestorOf(int u, int v) {
        return dfsIn[u] <= dfsIn[v] && dfsOut[u] >= dfsOut[v];
    }

    void dfs(int u, int p) {
        dfsIn[u] = ++dfn;
        fa[u][0] = p;
        for (int k = 1; k <= LOG; ++k)
            fa[u][k] = fa[ fa[u][k-1] ][k-1];
        for (int v: AL[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
        dfsOut[u] = ++dfn;
    }

    int lca(int u, int v) {
        if (isAncestorOf(u, v)) return u;
        if (isAncestorOf(v, u)) return v;
        for (int k = LOG; k >= 0; --k) {
            if (!isAncestorOf(fa[u][k], v))
                u = fa[u][k];
        }
        return fa[u][0];
    }

    void init_root(int root) {
        dfs(root, root);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    DSU::init(N);
    for (int i = 0; i < M; ++i) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        DSU::merge(u, v);
    }

    vector<int> sigma(N), sigmaInv(N);
    for (int i = 0; i < N; ++i) {
        cin >> sigma[i];
        --sigma[i];
        sigmaInv[sigma[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        if (!DSU::is_same_group(i, sigmaInv[i])) {
            cout << "impossible\n";
            return 0;
        }
    }

    LCA1::pre(N);
    vector<char> seen(N, 0);
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (!seen[i]) {
            seen[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (!seen[v]) {
                        seen[v] = 1;
                        LCA1::AL[u].push_back(v);
                        LCA1::AL[v].push_back(u);
                        q.push(v);
                    }
                }
            }
            LCA1::init_root(i);
        }
    }

    vector<int> label(N), pos(N);
    for (int i = 0; i < N; ++i) {
        label[i] = i;
        pos[i] = i;
    }

    vector<pair<int,int>> ops;
    ops.reserve(N * N);

    auto do_transpose = [&](int u, int v) {
        int w = LCA1::lca(u, v);
        vector<int> pu;
        for (int x = u; x != w; x = LCA1::fa[x][0]) pu.push_back(x);
        pu.push_back(w);
        vector<int> pv;
        for (int x = v; x != w; x = LCA1::fa[x][0]) pv.push_back(x);
        vector<int> P = pu;
        for (int i = (int)pv.size() - 1; i >= 0; --i)
            P.push_back(pv[i]);

        int L = (int)P.size();
        // 1) forward: i=0..L-2
        for (int i = 0; i + 1 < L; ++i) {
            int a = P[i], b = P[i+1];
            int A = label[a], B = label[b];
            swap(label[a], label[b]);
            pos[A] = b; pos[B] = a;
            ops.emplace_back(A+1, B+1);
        }
        // 2) backward: i=L-3..0
        for (int i = L - 3; i >= 0; --i) {
            int a = P[i], b = P[i+1];
            int A = label[a], B = label[b];
            swap(label[a], label[b]);
            pos[A] = b; pos[B] = a;
            ops.emplace_back(A+1, B+1);
        }
    };

    vector<int> pi(N);
    for (int i = 0; i < N; ++i) pi[i] = sigmaInv[i];
    vector<char> used(N, 0);
    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;
        vector<int> cyc;
        int x = i;
        do {
            used[x] = 1;
            cyc.push_back(x);
            x = pi[x];
        } while (x != i);

        if (cyc.size() <= 1) continue;
        int pivot = cyc[0];
        for (size_t j = 1; j < cyc.size(); ++j) {
            do_transpose(pivot, cyc[j]);
        }
    }
    cout << ops.size() << "\n";
    for (const auto &[fst, snd] : ops) {
        cout << fst << " " << snd << "\n";
    }
    return 0;
}
