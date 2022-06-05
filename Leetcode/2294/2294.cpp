class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int counter = 0;
        sort(nums.begin(),nums.end());
        int n = (int)nums.size();
        int minVal = -1;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                minVal = nums[i];
                continue;
            }
            if (nums[i] - minVal > k) {
                ++counter;
                minVal = nums[i];
            }
        }
        if (minVal != -1) {
            ++counter;
        }
        return counter;
    }
};