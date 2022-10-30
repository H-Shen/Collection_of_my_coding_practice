class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int n = 0;
        for (auto&i : nums) {
            if (i % 6 == 0) {
                sum += i;
                ++n;
            }
        }
        return (n == 0) ? 0 : (sum / n);
    }
};