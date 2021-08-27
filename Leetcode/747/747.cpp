class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int pos = -1;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] == maxVal) {
                pos = i;
                continue;
            }
            if (nums[i] * 2 > maxVal) {
                return -1;
            }
        }
        return pos;
    }
};