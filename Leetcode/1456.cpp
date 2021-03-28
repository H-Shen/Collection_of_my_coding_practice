class Solution {
public:
    int maxVowels(string s, int k) {
        int maxValue = 0;
        int i = 0;
        int counter = 0;
        for (; i < k; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ++counter;
            }
        }
        maxValue = max(maxValue, counter);
        int n = (int)s.size();
        for (int j = 0; i < n; ++i, ++j) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                --counter;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ++counter;
            }
            maxValue = max(maxValue, counter);
        }
        return maxValue;
    }
};