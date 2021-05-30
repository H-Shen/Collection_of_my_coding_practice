class Solution {
public:
    string makeGood(string s) {
        bool checkAgain;
        while (s.size() >= 2) {
            int n = (int)s.size();
            checkAgain = false;
            for (int i = 0; i < n-1; ++i) {
                if (islower(s[i]) && isupper(s[i+1]) && s[i] == tolower(s[i+1])) {
                    s.erase(i,2);
                    checkAgain = true;
                    break;
                }
                else if (isupper(s[i]) && islower(s[i+1]) && s[i] == toupper(s[i+1])) {
                    s.erase(i,2);
                    checkAgain = true;
                    break;
                }
            }
            if (!checkAgain) {
                break;
            }
        }
        return s;
    }
};