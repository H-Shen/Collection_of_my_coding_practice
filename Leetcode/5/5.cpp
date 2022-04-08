class Solution {
public:
    // O(n^2) in dp
    string longestPalindrome(string s) {
        int n = (int)s.size();
        int l = -1, r = -1, maxLength = 0;
        int left, right;
        int currLength = 0;
        // odd length
        for (int i = 0; i < n; ++i) {
            left = i;
            right = i;
            do {
                currLength = right - left + 1;
                if (currLength > maxLength) {
                    maxLength = currLength;
                    l = left;
                    r = right;
                }
                --left;
                ++right;
            } while (left >= 0 && right < n && s[left] == s[right]);
        }
        // even length
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                left = i;
                right = i+1;
                do {
                    currLength = right - left + 1;
                    if (currLength > maxLength) {
                        maxLength = currLength;
                        l = left;
                        r = right;
                    }
                    --left;
                    ++right;
                } while (left >= 0 && right < n && s[left] == s[right]);
            }
        }
        return s.substr(l, maxLength);
    }
};