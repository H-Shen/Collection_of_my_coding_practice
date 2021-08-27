class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        constexpr int MAXN = 12;
        bitset<MAXN> vis;
        vector<vector<int>> answer;
        int n = (int)nums.size();
        int allPossibles = 1 << n;
        for (int i = 0; i < allPossibles; ++i) {
            vector<int> result;
            for (int j = 0; j < n; ++j) {
                if (vis[j]) {
                    result.emplace_back(nums[j]);
                }
            }
            answer.emplace_back(result);
            vis = vis.to_ulong() + 1;
        }
        return answer;
    }
};