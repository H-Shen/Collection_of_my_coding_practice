class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsec(0);
        int curConsec(0);
        int lastVal(-1);
        for (size_t i = 0; i != nums.size(); ++i) {
            if (nums[i] == 1 && lastVal != 1) {
                curConsec = 1;
                lastVal = 1;
            } else if (nums[i] == 1 && lastVal == 1) {
                ++curConsec;
            } else if (nums[i] != 1) {
                lastVal = nums[i];
                curConsec = 0;
            }
            maxConsec = max(maxConsec, curConsec);
        }
        return maxConsec;
    }
};