class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int counter = 0;
        int n = (int)nums.size();
        vector<int> diff(n+1);
        vector<int> flipsNeeded(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                flipsNeeded[i] = 0;
            }
            else {
                flipsNeeded[i] = flipsNeeded[i-1] + diff[i];
            }
            // Case 1: nums[i] = 0 but it flips even times
            // Case 2: nums[i] = 1 but it flips odd times
            if ( (nums[i] == 0 && flipsNeeded[i] % 2 == 0) || (nums[i] == 1 && flipsNeeded[i] % 2 != 0) ) {
                ++counter;
                if (i+k-1>=n) {
                    counter = -1;
                    break;
                }
                ++diff[i];
                if (i == 0) {
                    flipsNeeded[i] = diff[i];
                } else {
                    flipsNeeded[i] = flipsNeeded[i-1] + diff[i];
                }
                --diff[i+k];
            }
        }
        return counter;
    }
};