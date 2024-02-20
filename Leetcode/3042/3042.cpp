class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        auto isPrefix = [&](const string& text, const string& pattern) {
            if (pattern.size() > text.size()) return false;
            auto it1 = pattern.begin();
            auto it2 = text.begin();
            while (it1 != pattern.end()) {
                if (*it1 != *it2) return false;
                ++it1;
                ++it2;
            }
            return true;
        };
        auto isSuffix = [&](const string& text, const string& pattern) {
            if (pattern.size() > text.size()) return false;
            auto it1 = pattern.rbegin();
            auto it2 = text.rbegin();
            while (it1 != pattern.rend()) {
                if (*it1 != *it2) return false;
                ++it1;
                ++it2;
            }
            return true;
        };
        int n = (int)words.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (isPrefix(words[j], words[i]) && isSuffix(words[j], words[i])) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};