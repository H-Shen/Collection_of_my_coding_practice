class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 3) {
            return false;
        }
        vector<int> minFromLeft(n);
        minFromLeft[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            minFromLeft[i] = min(nums[i], minFromLeft[i-1]);
        }
        set<int> s;
        for (int i = n - 1; i >= 2; --i) {
            s.insert(nums[i]);
            if (nums[i-1] <= *s.begin()) {
                continue;
            }
            auto iter = --s.lower_bound(nums[i-1]);
            if (minFromLeft[i-2] < *iter && *iter < nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};