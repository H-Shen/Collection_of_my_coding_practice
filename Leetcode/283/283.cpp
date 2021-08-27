class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it = remove(nums.begin(), nums.end(), 0);
        fill(it, nums.end(), 0);
    }
};