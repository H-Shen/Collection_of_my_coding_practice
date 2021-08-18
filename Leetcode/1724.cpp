// Kruskal重构树模版

namespace DSU {
    vector<int> father;
    void init(int n) {
        vector<int>().swap(father);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
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
        if (x == y) return;
        father[y] = x;
    }
}

vector<vector<int>> AL;
vector<int> weight;

namespace LCA {
    constexpr int N = 2e4+5;
    int n, l, dfn;
    vector<int> dfsIn, dfsOut;
    vector<vector<int> > fa;
    bitset<N> vis;
    void pre(int numberOfNodes) {
        // reset
        vis.reset();
        vector<int>().swap(dfsIn);
        vector<int>().swap(dfsOut);
        decltype(fa)().swap(fa);
        
        n = numberOfNodes;
        dfsIn.resize(n);
        dfsOut.resize(n);
        l = ceil(log2(n));
        dfn = 0;
        fa.resize(n, vector<int>(l+1));
    }
    void dfs(int u, int father) {
        vis[u] = true;
        dfsIn[u] = ++dfn;
        fa[u][0] = father;
        for (int i = 1; i <= l; ++i) {
            fa[u][i] = fa[fa[u][i-1]][i-1];
        }
        for (const auto &v : AL[u]) {
            if (v != father) dfs(v,u);
        }
        dfsOut[u] = ++dfn;
    }
    void init(int u) {
        dfs(u, u);
    }
    bool isAncestorOf(int u, int v) {
        return dfsIn[u] <= dfsIn[v] && dfsOut[u] >= dfsOut[v];
    }
    int lca(int u, int v) {
        if (isAncestorOf(u,v)) return u;
        else if (isAncestorOf(v,u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!isAncestorOf(fa[u][i],v)) {
                u = fa[u][i];
            }
        }
        return fa[u][0];
    }
}

class DistanceLimitedPathsExist {
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
        vector<int>().swap(weight);
        vector<vector<int>>().swap(AL);
        int m = (int)edgeList.size();
        weight.resize(n+m+1);
        AL.resize(n+m+1);
        DSU::init(n+m+1);
        sort(edgeList.begin(),edgeList.end(),[](const auto &l, const auto &r){
            return l[2] < r[2];
        });
        int id = n;
        int u,v,rootOfU,rootOfV,w;
        for (const auto &i : edgeList) {
            u = i[0];
            v = i[1];
            w = i[2];
            rootOfU = DSU::find(u);
            rootOfV = DSU::find(v);
            if (rootOfU != rootOfV) {
                weight[id] = w;
                AL[id].emplace_back(rootOfU);
                AL[rootOfU].emplace_back(id);
                AL[id].emplace_back(rootOfV);
                AL[rootOfV].emplace_back(id);
                DSU::merge(id, rootOfU);
                DSU::merge(id, rootOfV);
                ++id;
            }
        }
        LCA::pre(id);
        for (int i = 0; i < id; ++i) {
            if (!LCA::vis[i]) LCA::init(DSU::find(i));
        }
    }
    
    bool query(int p, int q, int limit) {
        if (DSU::find(p) != DSU::find(q)) return false;
        return weight[LCA::lca(p,q)] < limit;
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */