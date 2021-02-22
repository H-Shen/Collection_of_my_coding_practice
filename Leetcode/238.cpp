class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] * nums[i];
        }
        vector<int> suff(n);
        suff[0] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            suff[i] = suff[i - 1] * nums[n - 1 - i];
        }
        nums[0] = suff[n - 2];
        for (int i = 1; i < n - 1; ++i) {
            nums[i] = pre[i - 1] * suff[n - i - 2]; 
        }
        nums[n - 1] = pre[n - 2];
        return nums;
    }
};