class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > static_cast<int>(nums.size())) {
            k %= static_cast<int>(nums.size());
        }
        std::rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
    }
};