class Solution {
public:
    inline
    bool check(const string& s) {
        static auto f = [](const char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        return f(s.front()) && f(s.back());
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            if (check(words[i])) {
                ++cnt;
            }
        }
        return cnt;
    }
};