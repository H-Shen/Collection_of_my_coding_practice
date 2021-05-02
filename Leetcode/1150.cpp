class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!binary_search(nums.begin(), nums.end(), target)) {
            return false;
        }
        auto p = equal_range(nums.begin(), nums.end(), target);
        return (p.second-nums.begin()) - (p.first-nums.begin()) > n / 2;
    }
};