class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if ((int)__builtin_popcount(i) == k) {
                sum += nums[i];
            }
        }
        return sum;
    }
};