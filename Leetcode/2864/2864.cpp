class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zero = 0;
        int one = 0;
        for (const auto &i : s) {
            if (i == '0') ++zero;
            else ++one;
        }
        if (one == 1) {
            return string(zero, '0') + "1";
        }
        else if (one > 1) {
            return string(one-1, '1') + string(zero, '0') + "1";
        }
        return string(zero, '0');
    }
};