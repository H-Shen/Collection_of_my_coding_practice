class Solution {
public:
    char shift(char ch, int n) {
        return ch + (n % 26);
    }
    string replaceDigits(string s) {
        int n = (int)s.size();
        string str;
        char ch = 0;
        int m;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ch = s[i];
            } else {
                m = s[i] - '0';
                str.push_back(ch);
                str.push_back(shift(ch, m));
                ch = 0;
            }
        }
        if (ch != 0) {
            str.push_back(ch);
        }
        return str;
    }
};