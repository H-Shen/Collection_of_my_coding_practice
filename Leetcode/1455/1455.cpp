class Solution {
public:
    bool isPrefix(const string &pattern, const string &text) {
        if (pattern.empty()) return true;
        if (pattern.size() > text.size()) return false;
        for (size_t i = 0; i != pattern.size(); ++i) {
            if (pattern[i] != text[i]) return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string s;
        int idx = 1;
        do {
            iss >> s;
            if (isPrefix(searchWord, s)) { return idx; }
            ++idx;
        } while (iss);
        return -1;
    }
};