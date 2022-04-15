class Solution {
public:
    // reverse thinking
    int minMoves(vector<int>& nums) {
        int counter = 0;
        int minVal = *min_element(nums.begin(),nums.end());
        for (auto&i : nums) {
            counter += i - minVal;
        }
        return counter;
    }
};