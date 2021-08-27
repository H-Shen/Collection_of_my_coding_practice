class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> A;
        for (const auto &i : s) {
            ++A[i];
        }

        int maxPalindromeLen = 0;
        int maxOdd = 0;
        for (auto it : A) {
            if ((it.second) & 1) {
                maxOdd = max(maxOdd, it.second);
            } else {
                maxPalindromeLen = maxPalindromeLen + it.second;   // all even parts
            }
        }
        bool addMaxOddOne = false;
        for (auto it : A) {
            if ((it.second) & 1) {
                if (it.second == maxOdd && !addMaxOddOne) {
                    maxPalindromeLen = maxPalindromeLen + maxOdd;   // the max odd one
                    addMaxOddOne = true;
                } else {
                    maxPalindromeLen = maxPalindromeLen + it.second - 1;   // all odd ones except the max odd one
                }
            }
        }

        return maxPalindromeLen;
    }
};