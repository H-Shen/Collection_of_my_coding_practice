class Solution {
public:
    string reverseWords(string s) {
        while (s.back() == ' ') s.pop_back();
        reverse(s.begin(), s.end());
        while (s.back() == ' ') s.pop_back();
        int n = (int)s.size();
        bool insideWord = false;
        int startIndex = 0;
        int endIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (s.at(i) == ' ') {
                if (insideWord) {
                    insideWord = false;
                    reverse(s.begin() + startIndex, s.begin() + endIndex + 1);
                }
            } else {
                if (insideWord) {
                    endIndex = i;
                } else {
                    insideWord = true;
                    startIndex = i;
                    endIndex = i;
                }
            }
        }
        if (insideWord) {
            reverse(s.begin() + startIndex, s.begin() + endIndex + 1);
        }
        if (n > 1) {
            auto iter = s.begin();
            while (iter != s.end()) {
                if (*iter == ' ') {
                    auto iterNext = iter;
                    ++iterNext;
                    if (iterNext != s.end() && *iterNext == ' ') {
                        iter = s.erase(iter);
                    } else {
                        ++iter;
                    }
                } else {
                    ++iter;
                }
            }
        }
        return s;
    }
};