class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = (int)s.size();
        bool inAWord = false;
        int startIndex, endIndex;
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                if (inAWord) {
                    ++endIndex;
                }
                else {
                    inAWord = true;
                    startIndex = i;
                    endIndex = i;
                }
            }
            else {
                if (inAWord) {
                    inAWord = false;
                    reverse(s.begin() + startIndex, s.begin() + endIndex + 1);
                }
            }
        }
        if (inAWord) {
            reverse(s.begin() + startIndex, s.begin() + endIndex + 1);
        }
        reverse(s.begin(), s.end());
    }
};