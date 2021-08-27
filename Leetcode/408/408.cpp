class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        const regex r("([a-z]+|\\d+)");
        auto iter = word.begin();
        string s;
        int n;
        for (sregex_iterator it(abbr.begin(), abbr.end(), r), end; it != end; ++it) {
            s = it->str();
            if (isalpha(s.front())) {
                for (const auto &ch : s) {
                    if (iter == word.end() || *iter != ch) {
                        return false;
                    }
                    ++iter;
                }
            } else {
                try {
                    n = stoi(s);
                    // no zeroes allowed
                    if (n == 0) {
                        return false;
                    }
                    // no leading zeroes allowed
                    if (to_string(n) != s) {
                        return false;
                    }
                } catch (...) {
                    return false;
                }
                for (int i = 0; i < n; ++i) {
                    if (iter == word.end()) {
                        return false;
                    }
                    ++iter;
                }
            }
        }
        return iter == word.end();
    }
};