class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        for (auto &ch : firstWord) {
            ch = ch - 'a' + '0';
        }
        for (auto &ch : secondWord) {
            ch = ch - 'a' + '0';
        }
        for (auto &ch : targetWord) {
            ch = ch - 'a' + '0';
        }
        return stoll(firstWord) + stoll(secondWord) == stoll(targetWord);
    }
};