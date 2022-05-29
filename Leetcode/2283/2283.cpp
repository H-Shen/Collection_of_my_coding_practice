class Solution {
public:
    bool digitCount(string num) {
        int n = (int)num.size();
        for (int i = 0; i < n; ++i) {
            if ((int)count(num.begin(),num.end(),i+'0') != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};