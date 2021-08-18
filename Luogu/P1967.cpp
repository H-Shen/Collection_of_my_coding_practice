#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }

    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }

    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

// 用以判断连通性和构建Kruskal重构树
namespace DSU {
    vector<int> father;
    void init(int n) {
        vector<int>().swap(father);
        father.resize(n+5);
        iota(father.begin(),  father.end(), 0);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    // merge y to x
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        father[y] = x;
    }
}

struct Edge {
    int u,v,w;
    Edge() = default;
    Edge(int u, int v, int w) : u(u),v(v),w(w){}
};

int n,m,u,v,w;
vector<Edge> edgeList;
vector<int> weight; // kruskal重构树节点点权
vector<vector<int> > AL; // 存储kruskal重构树

namespace LCA {
    int dfn, n, l;
    vector<int> dfsIn, dfsOut;
    vector<vector<int>> fa;
    vector<bool> vis;
    void pre(int number_of_nodes) {
        n = number_of_nodes;
        dfsIn.resize(n+1);
        dfsOut.resize(n+1);
        vis.resize(n+1);
        dfn = 0;
        l = ceil(log2(n+1));
        fa.resize(n+1, vector<int>(l+1));
    }
    void dfs(int u, int father) {
        vis[u] = true;
        dfsIn[u] = ++dfn;
        fa[u][0] = father;
        for (int i = 1; i <= l; ++i) {
            fa[u][i] = fa[fa[u][i-1]][i-1];
        }
        for (const auto &v : AL[u]) {
            if (v != father) {
                dfs(v, u);
            }
        }
        dfsOut[u] = ++dfn;
    }
    bool isAncestorOf(int u,int v) {
        return dfsIn[u] <= dfsIn[v] && dfsOut[u] >= dfsOut[v];
    }
    int lca(int u, int v) {
        if (isAncestorOf(u,v)) return u;
        if (isAncestorOf(v,u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!isAncestorOf(fa[u][i],v)) {
                u = fa[u][i];
            }
        }
        return fa[u][0];
    }
    void init(int root) {
        dfs(root, root);
    }
}

int main() {
    IO::read(n,m);
    for (int i = 0; i < m; ++i) {
        IO::read(u,v,w);
        edgeList.emplace_back(Edge(u,v,w));
    }
    // 构建Kruskal重构树
    sort(edgeList.begin(),edgeList.end(),[](const auto &l, const auto &r){
        return l.w > r.w;
    });
    // 节点数+边数
    DSU::init(n+1+m+1);
    weight.resize(n+1+m+1);
    AL.resize(n+1+m+1);
    // 非叶子节点初始编号
    int nodeId = n;
    int root_of_u, root_of_v;
    for (const auto &e : edgeList) {
        root_of_u = DSU::find(e.u);
        root_of_v = DSU::find(e.v);
        if (root_of_u != root_of_v) {
            ++nodeId;
            weight[nodeId] = e.w;
            // 将nodeId直接作为两个集合的根
            DSU::father[root_of_u] = nodeId;
            DSU::father[root_of_v] = nodeId;
            AL[root_of_u].emplace_back(nodeId);
            AL[nodeId].emplace_back(root_of_u);
            AL[root_of_v].emplace_back(nodeId);
            AL[nodeId].emplace_back(root_of_v);
        }
    }
    LCA::pre(nodeId+1);
    // 防止森林的情况
    for (int i = 1; i <= nodeId; ++i) {
        if (!LCA::vis[i]) {
            // 从它的根开始dfs
            LCA::init(DSU::find(i));
        }
    }
    int q;
    IO::read(q);
    while (q--) {
        IO::read(u,v);
        if (DSU::find(u) != DSU::find(v)) {
            IO::writeln(-1);
        } else {
            IO::writeln(weight[LCA::lca(u,v)]);
        }
    }
    return 0;
}
