class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        auto p = minmax_element(nums.begin(),nums.end());
        int minVal = *(p.first);
        int maxVal = *(p.second);
        for (auto&i : nums) {
            if (i != minVal && i != maxVal) return i;
        }
        return -1;
    }
};