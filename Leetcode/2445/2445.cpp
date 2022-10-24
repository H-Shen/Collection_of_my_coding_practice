vector<int> dfn;
vector<int> maxDfn, minDfn;
vector<vector<int>> adj;
int nodes;
int dfsRank;
int root;

void dfs(int v) {
    dfn[v] = dfsRank;
    ++dfsRank;
    for (const auto &child : adj[v]) {
        dfs(child);
    }
}

int dpMaxDfn(int v) {
    int vDfn = dfn[v];
    if (maxDfn[vDfn] != -1) {
        return maxDfn[vDfn];
    }
    maxDfn[vDfn] = vDfn;
    for (const auto &child : adj[v]) {
        maxDfn[vDfn] = max(maxDfn[vDfn], dpMaxDfn(child));
    }
    return maxDfn[vDfn];
}

int dpMinDfn(int v) {
    int vDfn = dfn[v];
    if (minDfn[vDfn] != -1) {
        return minDfn[vDfn];
    }
    minDfn[vDfn] = vDfn;
    for (const auto &child : adj[v]) {
        minDfn[vDfn] = min(minDfn[vDfn], dpMinDfn(child));
    }
    return minDfn[vDfn];
}

class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        root = 1;
        nodes = n;
        decltype(adj)().swap(adj);
        adj.resize(n+1);
        for (int i = 2; i <= n; ++i) {
            int parent = i>>1;
            adj[parent].emplace_back(i);
        }
        decltype(dfn)().swap(dfn);
        dfn.resize(n+1);
        dfsRank = 0;
        dfs(root);
        vector<int>().swap(maxDfn);
        maxDfn.resize(n,-1);
        vector<int>().swap(minDfn);
        minDfn.resize(n,-1);
        vector<int> diff(n+1);
        int l, r;
        for (const auto &i : queries) {
            l = dpMinDfn(i);
            r = dpMaxDfn(i);
            ++diff[l];
            --diff[r+1];
        }
        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i-1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (diff[i] & 1) ++ans;
        }
        return ans;
    }
};