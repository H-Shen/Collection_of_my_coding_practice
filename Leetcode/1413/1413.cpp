class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = numeric_limits<int>::max();
        int initial = 0;
        for (const auto &i : nums) {
            initial += i;
            minVal = min(minVal, initial);
        }
        if (minVal >= 0) {
            return 1;
        }
        return abs(minVal) + 1;
    }
};