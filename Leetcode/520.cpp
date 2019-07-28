class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper = true;
        bool allLower = true;
        for (const auto &i : word) {
            if (isupper(i)) {
                allLower = false;
            } else {
                allUpper = false;
            }
        }
        if (allLower || allUpper) {
            return true;
        }
        bool firstUpperOtherLower = true;
        for (size_t i = 0; i != word.size(); ++i) {
            if (i == 0 && islower(word[i])) {
                firstUpperOtherLower = false;
                break;
            } else if (i != 0 && isupper(word[i])) {
                firstUpperOtherLower = false;
                break;
            }
        }
        if (word.size() == 1) {
            firstUpperOtherLower = false;
        }
        return firstUpperOtherLower;
    }
};