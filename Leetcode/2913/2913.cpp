class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = (int)nums.size();
        int s = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unordered_set<int> unset;
                for (int k = i; k <= j; ++k) {
                    unset.insert(nums[k]);
                }
                s += (int)unset.size() * (int)unset.size();
            }
        }
        return s;
    }
};