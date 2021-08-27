vector<vector<int>> AL;
vector<int> weight;

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
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        father[y] = x;
    }
    bool isSameGroup(int x,int y) {
        return find(x) == find(y);
    }
}

namespace LCA {
    constexpr int MAXN = 2e5+5;
    bitset<MAXN> vis;
    int dfn,l,n;
    vector<int> dfsIn,dfsOut;
    vector<vector<int>> fa;
    void pre(int numberOfNodes) {
        vector<int>().swap(dfsIn);
        vector<int>().swap(dfsOut);
        decltype(fa)().swap(fa);
        n = numberOfNodes;
        dfn = 0;
        l = ceil(log2(n));
        dfsIn.resize(n);
        dfsOut.resize(n);
        fa.resize(n, vector<int>(l+1));
        vis.reset();
    }
    bool isAncestorOf(int u, int v) {
        return dfsIn[u] <= dfsIn[v] && dfsOut[u] >= dfsOut[v];
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
    void init(int root) {
        dfs(root,root);
    }
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        decltype(AL)().swap(AL);
        vector<int>().swap(weight);
        sort(edgeList.begin(),edgeList.end(),[](const auto &l, const auto &r){
            return l[2] < r[2];
        });
        int m = (int)edgeList.size();
        weight.resize(n+m+1);
        AL.resize(n+m+1);
        DSU::init(n+m+1);
        int u,v,w,rootOfU,rootOfV;
        int id = n;
        // 构建Kruskal重构树
        for (const auto &i : edgeList) {
            u = i[0];
            v = i[1];
            w = i[2];
            rootOfU = DSU::find(u);
            rootOfV = DSU::find(v);
            if (rootOfU != rootOfV) {
                weight[id] = w;
                DSU::merge(id, rootOfU);
                DSU::merge(id, rootOfV);
                AL[id].emplace_back(rootOfU);
                AL[rootOfU].emplace_back(id);
                AL[id].emplace_back(rootOfV);
                AL[rootOfV].emplace_back(id);
                ++id;
            }
        }
        LCA::pre(id);
        for (int i = 0; i < id; ++i) {
            if (!LCA::vis[i]) LCA::init(DSU::find(i));
        }
        // 查询并输出
        int q = (int)queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; ++i) {
            u = queries[i][0];
            v = queries[i][1];
            w = queries[i][2];
            if (DSU::find(u) == DSU::find(v) && weight[LCA::lca(u,v)] < w) {
                ans[i] = true;
            }
        }
        return ans;
    }
};