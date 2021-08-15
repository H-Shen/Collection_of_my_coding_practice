class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = (int)nums.size();
        vector<int> ans(n);
        auto iter = nums.cbegin();
        for (int i = 0; i < n; i += 2) {
            ans[i] = *iter;
            ++iter;
        }
        for (int i = 1; i < n; i += 2) {
            ans[i] = *iter;
            ++iter;
        }
        return ans;
    }
};