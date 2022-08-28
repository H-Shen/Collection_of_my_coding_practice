class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // 1 2 4 5
        // 1 3 7 12
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        int m = (int)queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            if (queries[i] < pre[0]) {
                ans[i] = 0;
            }
            else {
                if (binary_search(pre.begin(),pre.end(),queries[i])) {
                    auto iter = lower_bound(pre.begin(),pre.end(),queries[i]);
                    ans[i] = (int)(iter - pre.begin()) + 1; 
                }
                else {
                    auto iter = lower_bound(pre.begin(),pre.end(),queries[i]);
                    --iter;
                    ans[i] = (int)(iter - pre.begin()) + 1; 
                }
            }
        }
        return ans;
    }
};