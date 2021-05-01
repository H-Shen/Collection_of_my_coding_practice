class Solution {
public:
    int calculateTime(string keyboard, string word) {
        constexpr int MAXN = 26;
        int pos[MAXN]{};
        for (int i = 0; i < MAXN; ++i) {
            pos[keyboard[i] - 'a'] = i;
        }
        int index = 0;
        int result = 0;
        for (size_t i = 0; i != word.size(); ++i) {
            if (i == 0) {
                result += abs(pos[word[i]-'a']);
            } else {
                result += abs(pos[word[i]-'a'] - index);
            }
            index = pos[word[i]-'a'];
        }
        return result;
    }
};