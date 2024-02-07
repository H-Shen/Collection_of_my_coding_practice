class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        // 1 or 1 = 1
        // 0 or 0 = 0
        // 0 or 1 = 1
        // 1 or 0 = 1
        int n = (int)nums.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((nums[i] | nums[j]) % 2 == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};