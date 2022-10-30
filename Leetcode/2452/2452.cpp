class Solution {
public:
    inline
    bool check(const string&l, const string&r) const {
        int cnt = 0;
        for (size_t i = 0; i != l.size(); ++i) {
            if (l[i] != r[i]) {
                ++cnt;
                if (cnt > 2) return false;
            }
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<string> ans;
        for (const auto &i : queries) {
            for (const auto &word : dictionary) {
                if (check(i, word)) {
                    ans.emplace_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};