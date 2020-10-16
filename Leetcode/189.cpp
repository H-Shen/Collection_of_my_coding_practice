class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        k %= (int)nums.size();
        // Reverse the whole vector
        reverse(nums.begin(), nums.end());
        // Reverse the first part
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the second part
        reverse(nums.begin() + k, nums.end());
    }
};