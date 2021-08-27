class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = (int)nums.size();
        sort(nums.begin(), nums.end(), greater<>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int cur = 0;
        int rest;
        int i;
        vector<int> result;
        for (i = 0; i < n; ++i) {
            cur += nums[i];
            result.emplace_back(nums[i]);
            rest = sum - cur;
            if (rest < cur) break;
        }
        sort(result.begin(), result.end(), greater<>());
        return result;
    }
};