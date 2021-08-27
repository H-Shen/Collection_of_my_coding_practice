constexpr int MAXN = 15;
class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(vector<int> v, const vector<vector<int>> &AL) {
        if (v.back() == n-1) {
            ans.emplace_back(v);
            return;
        }
        for (const auto &j : AL[v.back()]) {
            if (count(v.begin(),v.end(),j) == 0) {
                v.emplace_back(j);
                dfs(v, AL);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        decltype(ans)().swap(ans);
        n = (int)graph.size();
        vector<int> v;
        v.emplace_back(0);
        dfs(v, graph);
        return ans;
    }
};