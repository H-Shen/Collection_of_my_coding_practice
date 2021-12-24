class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int T = n<<1;
        int q = (int)queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
            int t = queries[i][0];
            int index = queries[i][1];
            if (t > T) {
                t %= T;
            }
            if (t <= n) {
                ans[i] = (index >= n - t) ? -1 : nums[index + t];
            }
            else {
                ans[i] = (index >= t - n) ? -1 : nums[index];
            }
        }
        return ans;
    }
};