class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> vec;
        int n;
        while (nums.size() > 1) {
            n = (int)nums.size();
            vector<int> vec(n-1);
            for (int i = 0; i < n-1; ++i) {
                vec[i] = (nums[i] + nums[i+1]) % 10;
            }
            swap(vec, nums);
        }
        return nums[0];
    }
};