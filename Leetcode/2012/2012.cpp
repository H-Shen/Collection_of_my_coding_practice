class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> maxFromLeft(n);
        maxFromLeft[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            maxFromLeft[i] = max(maxFromLeft[i-1], nums[i]);
        }
        vector<int> minFromRight(n);
        minFromRight[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            minFromRight[i] = min(minFromRight[i+1], nums[i]);
        }
        int counter = 0;
        for (int i = 1; i <= n-2; ++i) {
            if (maxFromLeft[i-1] < nums[i] && nums[i] < minFromRight[i+1]) {
                counter += 2;
            }
            else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                counter += 1;
            }
        }
        return counter;
    }
};