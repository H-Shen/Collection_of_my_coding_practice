class Solution {
public:
    bool isPalindrome(const string &s) {
        string sCopy(s);
        reverse(sCopy.begin(), sCopy.end());
        return sCopy == s;
    }
    int removePalindromeSub(string s) {
        return (isPalindrome(s)) ? 1 : 2;
    }
};