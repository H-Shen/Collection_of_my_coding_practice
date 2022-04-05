class Solution {
public:
    void dfs(vector<int>& candidates, int index, int target, vector<int>comb, vector<vector<int>>&ans) {
        if (index == (int)candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(comb);
            return;
        }
        // only two ways to dfs:
        // 1. not to choose candidates[index]
        dfs(candidates, index+1, target, comb, ans);
        // 2. choose candidates[index]
        if (target >= candidates[index]) {
            comb.emplace_back(candidates[index]);
            dfs(candidates, index, target - candidates[index], comb, ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        dfs(candidates, 0, target, vector<int>(), ans);
        return ans;
    }
};