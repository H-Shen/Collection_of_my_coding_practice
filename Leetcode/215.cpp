class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<>());
        return nums.at(static_cast<unsigned long>(k - 1));
    }
};