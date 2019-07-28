class Solution {
public:
    string convertToBase7(int num) {
        string s;
        bool isNeg = num < 0;
        if (isNeg) {
            num = -num;
        }
        while (num) {
            s = to_string(num % 7) + s;
            num /= 7;
        }
        if (isNeg) {
            s = "-" + s;
        }
        if (s.empty()) {
            s = "0";
        }
        return s;
    }
};