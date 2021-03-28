class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int maxLength = 1;
        int currentLength = 1;
        int n = (int)nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++currentLength;
            }
            else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = max(maxLength, currentLength);
        return maxLength;
    }
};