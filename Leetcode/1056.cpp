class Solution {
public:
    bool confusingNumber(int N) {
        string s = to_string(N);
        for (const auto &ch : s) {
            if (ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '7') {
                return false;
            }
        }
        string sRev(s);
        reverse(sRev.begin(), sRev.end());
        for (auto &ch : sRev) {
            if (ch == '6') {
                ch = '9';
            } else if (ch == '9') {
                ch = '6';
            }
        }
        while (sRev.size() > 1 && sRev[0] == '0') {
            sRev = sRev.substr(1);
        };
        return sRev != s;
    }
};