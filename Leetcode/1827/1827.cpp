class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        vector<int> p = nums;
        int n = (int)p.size();
        for (int i = 1; i < n; ++i) {
            p[i] = max(p[i-1]+1, p[i]);
        }
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            counter += abs(p[i] - nums[i]);
        }
        return counter;
    }
};