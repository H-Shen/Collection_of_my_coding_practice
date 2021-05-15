constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 10005;

class Solution {
public:
    vector<int> dp, weight;
    vector<vector<int> > AL;
    bitset<MAXN> vis;
    int subtreeSum(int u, int father_of_u) {
        if (dp[u] != INF) {
            return dp[u];
        }
        dp[u] = weight[u];
        for (const auto &v : AL[u]) {
            if (v != father_of_u) {
                dp[u] += subtreeSum(v, u);
            }
        }
        return dp[u];
    }
    void dfs(int u, int father_of_u) {
        if (vis[u]) {
            return;
        }
        vis[u] = true;
        for (const auto &v : AL[u]) {
            if (v != father_of_u) {
                dfs(v, u);
            }
        }
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int>().swap(dp);
        dp.resize(nodes, INF);
        vector<int>().swap(weight);
        weight = value;
        decltype(AL)().swap(AL);
        AL.resize(nodes);
        int u, v;
        for (int i = 0; i < nodes; ++i) {
            u = i;
            v = parent[i];
            if (v != -1) {
                AL[u].emplace_back(v);
                AL[v].emplace_back(u);
            }
        }
        vis.reset();
        for (int i = 0; i < nodes; ++i) {
            if (subtreeSum(i, parent[i]) == 0) {
                dfs(i, parent[i]);
            }
        }
        return nodes - (int)vis.count();
    }
};