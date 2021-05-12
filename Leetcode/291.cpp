class Solution {
public:
    bool startsWith(const string& pattern, const string& text) {
        if (pattern.size() > text.size()) {
            return false;
        }
        for (size_t i = 0; i != pattern.size(); ++i) {
            if (pattern[i] != text[i]) {
                return false;
            }
        }
        return true;
    }
    bool dfs(string pattern, string s, unordered_map<char,string> bimap, unordered_set<string> unset) {
        if (pattern.empty()) {
            return s.empty();
        }
        char ch = pattern.front();
        if (bimap.find(ch) != bimap.end()) {
            string mapped = bimap[ch];
            if (mapped.size() > s.size()) {
                return false;
            }
            if (!startsWith(mapped, s)) {
                return false;
            }
            return dfs(pattern.substr(1), s.substr(mapped.size()), bimap, unset);
        }
        else {
            int length = (int)s.size();
            for (int i = 1; i <= length; i++) {
                string mapped = s.substr(0, i);
                if (unset.find(mapped) != unset.end()) {
                    continue;
                }
                bimap[ch] = mapped;
                unset.insert(mapped);
                if (dfs(pattern.substr(1), s.substr(i), bimap, unset)) {
                    return true;
                }
                bimap.erase(ch);
                unset.erase(mapped);
            }
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string s) {
        if (s.size() < pattern.size()) {
            return false;
        }
        return dfs(pattern, s, unordered_map<char,string>(), unordered_set<string>());
    }
};