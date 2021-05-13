constexpr int MAXN = 26;

class Solution {
public:
    vector<array<int, MAXN> > dp;
    vector<bool> vis;
    vector<vector<int> > AL;
    string weight;
    array<int, MAXN> solve(int u, int father_of_u) {
        if (vis[u]) {
            return dp[u];
        }
        vis[u] = true;
        dp[u][weight[u] - 'a']++;
        for (const auto &v : AL[u]) {
            if (v == father_of_u) {
                continue;
            }
            auto temp = solve(v, u);
            for (int i = 0; i < MAXN; ++i) {
                dp[u][i] += temp[i];
            }
        }
        return dp[u];
    }
    vector<int> ans;
    void dfs(int u, int father_of_u) {
        ans[u] = solve(u, father_of_u)[weight[u] - 'a'];
        for (const auto v : AL[u]) {
            if (v == father_of_u) {
                continue;
            }
            dfs(v, u);
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        decltype(vis)().swap(vis);
        decltype(dp)().swap(dp);
        decltype(AL)().swap(AL);
        decltype(ans)().swap(ans);
        vis.resize(n, false);
        dp.resize(n);
        ans.resize(n);
        AL.resize(n);
        weight = labels;
        for (const auto &i : edges) {
            AL[i[0]].emplace_back(i[1]);
            AL[i[1]].emplace_back(i[0]);
        }
        dfs(0, -1);
        return ans;
    }
};