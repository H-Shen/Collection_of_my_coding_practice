class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n);
        vector<int> leftSum(n);
        for (int i = 1; i < n; ++i) {
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
        vector<int> rightSum(n);
        for (int i = n-2; i >= 0; --i) {
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};