class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        size_t pos = max_element(nums.begin(), nums.end() - (k-1)) - nums.begin();
        vector<int> result(nums.begin() + pos, nums.begin() + pos + k);
        return result;
    }
};