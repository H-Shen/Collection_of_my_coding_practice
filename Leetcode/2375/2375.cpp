constexpr int MAXN = 12;

class Solution {
public:
    string ans;
    bool less(const string&l, const string&r) const {
        if (l.size() == r.size()) {
            for (size_t i = 0; i != l.size(); ++i) {
                if (l[i] > r[i]) {
                    return false;
                }
            }
            return true;
        }
        return l.size() < r.size();
    }
    void dfs(string& current, string& pattern, bitset<MAXN>& vis) {
        if (current.size() == pattern.size() + 1) {
            if (ans.empty()) {
                ans = current;
            }
            else if (less(current, ans)) {
                ans = current;
            }
            return;
        }
        for (int i = 1; i <= 9; ++i) {
            // check if the string matches the pattern
            if (!vis[i] && (current.empty() || (pattern[current.size()-1] == 'I' && current.back() < i+'0') || (pattern[current.size()-1] == 'D' && current.back() > i+'0'))) {
                vis[i] = true;
                current.push_back(i + '0');
                dfs(current, pattern, vis);
                current.pop_back();
                vis[i] = false;
            }
        }
    }
    string smallestNumber(string pattern) {
        ans.clear();
        bitset<MAXN> vis;
        string current;
        dfs(current, pattern, vis);
        return ans;
    }
};