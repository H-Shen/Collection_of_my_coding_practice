class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = nums[nums[i]];
        }
        return A;
    }
};