class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = remove(nums.begin(), nums.end(), val);
        return static_cast<int>(distance(nums.begin(), it));
    }
};