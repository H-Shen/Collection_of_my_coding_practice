class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        vector<int> numsCopy(nums);
        sort(numsCopy.begin(), numsCopy.end());
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            vector<int> numsCopyCopy(numsCopy);
            rotate(numsCopyCopy.begin(), numsCopyCopy.begin() + i, numsCopyCopy.end());
            if (numsCopyCopy == nums) return true;
        }
        return false;
    }
};