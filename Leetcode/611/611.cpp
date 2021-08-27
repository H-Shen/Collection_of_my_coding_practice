class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        int n = (int)nums.size();
        if (n <= 2) return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        int temp, k;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j < n; ++j) {
                temp = nums[i] + nums[j];
                if (temp <= nums[0]) continue;
                auto iter = lower_bound(nums.begin(),nums.end(),temp);
                --iter;
                k = (int)(iter - nums.begin());
                if (k > j) {
                    ans += k-j;
                }
            }
        }
        return ans;
    }
};