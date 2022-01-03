class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // LIS越长 LIS各元素增长率越小
        int n = (int)nums.size();
        vector<int> lis;
        for (int i = 0; i < n; ++i) {
            auto iter = lower_bound(lis.begin(),lis.end(),nums[i]);
            // 在当前LIS中没有比它大的或者相等的了
            if (iter == lis.end()) {
                lis.emplace_back(nums[i]);
            }
            // 在当前LIS中有比它大的或相等的 替换掉那个大的或相等的
            else {
                *iter = nums[i];
            }
        }
        return (int)lis.size();
    }
};