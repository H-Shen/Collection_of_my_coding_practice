class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) ans.emplace_back(i);
        }
        return ans;
    }
};