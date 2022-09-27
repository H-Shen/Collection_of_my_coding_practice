class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unordered_map<int,int> length2val;
        int n = (int)nums.size();
        int currLength = 1;
        length2val[currLength] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) {
                ++currLength;
            }
            else {
                if (length2val.count(currLength) == 0) {
                    length2val[currLength] = nums[i-1];
                }
                else {
                    length2val[currLength] = max(length2val[currLength], nums[i-1]);
                }
                currLength = 1;
            }
        }
        if (length2val.count(currLength) == 0) {
            length2val[currLength] = nums[n-1];
        }
        else {
            length2val[currLength] = max(length2val[currLength], nums[n-1]);
        }
        int maxVal = 0;
        for (auto&[k,v] : length2val) {
            maxVal = max(maxVal, v);
        }
        int maxLength = 0;
        for (auto&[k,v] : length2val) {
            if (v == maxVal) {
                maxLength = max(maxLength, k);
            }
        }
        return maxLength;
    }
};