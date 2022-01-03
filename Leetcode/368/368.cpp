class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(),nums.end());  // 保证小的在大的前面
        vector<int> dp(n, 1);
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (nums[j] % nums[i] == 0) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        vector<int> ans;
        int maxLength = *max_element(dp.begin(),dp.end());
        int currentMaxLength = maxLength;
        int index = n-1;
        for (; index >= 0; --index) {
            if (dp[index] == currentMaxLength) {
                ans.emplace_back(nums[index]);
                --currentMaxLength;
                break;
            }
        }
        while ((int)ans.size() < maxLength) {
            if (dp[index] == currentMaxLength && ans.back() % nums[index] == 0) {
                ans.emplace_back(nums[index]);
                --currentMaxLength;
            }
            --index;   
        }
        return ans;
    }
};