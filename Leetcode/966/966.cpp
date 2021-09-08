class Solution {
public:
    string f(string s) {
        for (auto &ch : s) {
            ch = tolower(ch);
        }
        return s;
    }
    string g(string s) {
        for (auto &ch : s) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ch = 'a';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = (int)queries.size();
        int m = (int)wordlist.size();
        unordered_set<string> unset(wordlist.begin(),wordlist.end());
        unordered_map<string, string> unmap;
        string s;
        for (int i = 0; i < m; ++i) {
            s = f(wordlist[i]);
            if (unmap.find(s) == unmap.end()) {
                unmap[s] = wordlist[i];
            }
        }
        unordered_map<string, string> unmap2;
        for (int i = 0; i < m; ++i) {
            s = g(wordlist[i]);
            if (unmap2.find(s) == unmap2.end()) {
                unmap2[s] = wordlist[i];
            }
        }
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            if (unset.find(queries[i]) != unset.end()) {
                ans[i] = queries[i];
                continue;
            }
            s = f(queries[i]);
            if (unmap.find(s) != unmap.end()) {
                ans[i] = unmap[s];
                continue;
            }
            s = g(queries[i]);
            if (unmap2.find(s) != unmap2.end()) {
                ans[i] = unmap2[s];
            }
        }
        return ans;
    }
};