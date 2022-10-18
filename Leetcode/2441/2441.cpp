class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_set<int> unset(nums.begin(),nums.end());
        int ans = -1;
        for (auto& i : nums) {
            if (i > 0 && unset.count(-i) > 0) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};