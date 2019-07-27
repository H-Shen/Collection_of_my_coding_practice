class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int maxn = 10000;
        int pos = 0, minGap = maxn, len = static_cast<int>(letters.size());
        int gap;
        for (int i = 0; i < len; ++i) {
            gap = static_cast<int>(letters[i]) - static_cast<int>(target);
            if (letters[i] > target && gap < minGap) {
                pos = i;
                minGap = gap;
            }
        }
        return letters[pos];
    }
};