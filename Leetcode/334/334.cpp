class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 3) {
            return false;
        }
        vector<int> minFromLeft(n);
        minFromLeft[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            minFromLeft[i] = min(nums[i],minFromLeft[i-1]);
        }
        vector<int> maxFromRight(n);
        maxFromRight[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            maxFromRight[i] = max(nums[i],maxFromRight[i+1]);
        }
        for (int i = 1; i <= n-2; ++i) {
            if (minFromLeft[i-1] < nums[i] && nums[i] < maxFromRight[i+1]) {
                return true;
            }
        }
        return false;
    }
};