class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cand;
    int t;
    int n;
    void dfs(vector<int> v, int currentIndex, int currentSum) {
        if (currentSum == t) {
            ans.emplace_back(v);
            return;
        }
        for (int i = currentIndex; i < n; ++i) {
            // Find duplicated elements
            if (i > currentIndex && cand[i] == cand[i-1]) {
                continue;
            }
            // End of dfs
            if (currentSum + cand[i] > t) {
                return;
            }
            v.emplace_back(cand[i]);
            dfs(v, i+1, currentSum + cand[i]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>().swap(ans);
        vector<int>().swap(cand);
        cand = candidates;
        t = target;
        n = (int)candidates.size();
        sort(cand.begin(),cand.end());
        dfs(vector<int>(), 0, 0);
        return ans;
    }
};