class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (binary_search(nums.begin(), nums.end(), target))
            return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        return distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target));
    }
};