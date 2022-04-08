class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }
        sort(nums.begin(),nums.end());
        int n = (int)nums.size();
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] + 1 != nums[i+1]) {
                return false;
            }
        }
        return true;
    }
};