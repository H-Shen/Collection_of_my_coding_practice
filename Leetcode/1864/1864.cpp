class Solution {
public:
    int countSwaps(const string &oldStr, const string &newStr) {
        int counter = 0;
        for (size_t i = 0; i != oldStr.size(); ++i) {
            if (oldStr[i] != newStr[i]) {
                ++counter;
            }
        }
        return counter / 2;
    }
    int minSwaps(string s) {
        int zero = count(s.begin(),s.end(),'0');
        int one = count(s.begin(),s.end(),'1');
        if (abs(zero-one) > 1) {
            return -1;
        }
        int ans = numeric_limits<int>::max();
        string str;
        if (zero == one) {
            str.clear();
            for (int i = 0; i < zero; ++i) {
                str.push_back('0');
                str.push_back('1');
            }
            ans = min(ans, countSwaps(s, str));
            str.clear();
            for (int i = 0; i < zero; ++i) {
                str.push_back('1');
                str.push_back('0');
            }
            ans = min(ans, countSwaps(s, str));
        }
        else if (zero > one) {
            str.clear();
            for (int i = 0; i < one; ++i) {
                str.push_back('0');
                str.push_back('1');
            }
            str.push_back('0');
            ans = min(ans, countSwaps(s, str));
        }
        else {
            str.clear();
            for (int i = 0; i < zero; ++i) {
                str.push_back('1');
                str.push_back('0');
            }
            str.push_back('1');
            ans = min(ans, countSwaps(s, str));
        }
        return ans;
    }
};