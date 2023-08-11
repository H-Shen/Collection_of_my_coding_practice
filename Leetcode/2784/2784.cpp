class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int length = (int)nums.size();
        if (length == 1) return false;
        int n = length-1;
        for (int i = 0; i < length-2; ++i) {
            if (nums[i] != i+1) return false;
        }
        if (nums[length-1] != n || nums[length-2] != n) {
            return false;
        }
        return true;
    }
};