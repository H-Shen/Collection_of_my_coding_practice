class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = (int)nums.size();
        int l = 0;
        int r = n-1;
        while (l < n - 1 && nums[l] <= nums[l+1]) {
            ++l;
        }
        while (r > 0 && nums[r-1] <= nums[r]) {
            --r;
        }
        if (l==n-1) {
            return true;
        }
        if (r-l>=2) {
            return false;
        }
        if (l==0 || r==n-1) {
            return true;
        }
        if (nums[r+1]>=nums[l] || nums[l-1] <= nums[r]) {
            return true;
        }
        return false;
    }
};