class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int s = 0;
        int maxVal = *max_element(nums.begin(),nums.end());
        while (k--) {
            s += maxVal;
            ++maxVal;
        }
        return s;
    }
};
