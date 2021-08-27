class Solution {
public:
    int findNumbers(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [](int x) {
            int counter = 0;
            while (x > 0) {
                ++counter;
                x /= 10;
            }
            return counter % 2 == 0;
        });
    }
};