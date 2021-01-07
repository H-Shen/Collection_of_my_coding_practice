class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int counter = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j] && i < j) {
                    ++counter;
                }
            }
        }
        return counter;
    }
};