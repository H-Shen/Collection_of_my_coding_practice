class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        auto it = s.crbegin();
        for (; it != s.crend(); ++it) {
            if (*it != ' ') {
                break;
            }
        }

        for (; it != s.crend(); ++it) {
            if (*it == ' ') {
                break;
            } else {
                ++counter;
            }
        }
        return counter;
    }
};