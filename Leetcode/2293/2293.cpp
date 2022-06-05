class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n;
        while (nums.size() > 1) {
            n = (int)nums.size();
            vector<int> newNums(n/2);
            for (int i = 0; i < n/2; ++i) {
                if (i & 1) {
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
                else {
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
            }
            swap(nums, newNums);
        }
        return nums[0];
    }
};