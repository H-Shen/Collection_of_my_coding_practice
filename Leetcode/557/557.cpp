class Solution {
public:
    string reverseWords(string s) {
        string res;
        bool inAWord = false;
        string tmp;
        for (const auto &i : s) {
            if (inAWord && i != ' ') {
                tmp += i;
            } else if (inAWord) {
                reverse(tmp.begin(), tmp.end());
                res += tmp + " ";
                tmp = "";
                inAWord = false;
            } else if (i != ' ') {
                tmp += i;
                inAWord = true;
            }
        }
        if (!tmp.empty()) {
            reverse(tmp.begin(), tmp.end());
            res = res + tmp;
        }
        return res;
    }
};