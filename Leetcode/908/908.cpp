class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        auto p = minmax_element(nums.begin(), nums.end());
        int minVal = *(p.first);
        int maxVal = *(p.second);
        if (minVal + k >= maxVal - k) {
            return 0;
        }
        return maxVal - minVal - 2*k;
    }
};