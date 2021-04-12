class Solution {
public:
    int arraySign(vector<int>& nums) {
        for (auto &i : nums) {
            if (i > 0) i = 1;
            else if (i < 0) i = -1;
            else i = 0;
        }
        int result = 1;
        for (auto &i : nums) {
            result *= i;
        }
        return result;
    }
};