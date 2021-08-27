constexpr int MAXN = 10;

string_view getSubstring(const string_view &s, int i, int length) {
    return s.substr(i,length);
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < MAXN) return ans;
        int n = (int)s.size();
        unordered_map<string_view,int> unmap;
        for (int i = 0; i + MAXN - 1 < n; ++i) {
            ++unmap[getSubstring(s,i,MAXN)];
        }
        for (const auto &[k,v] : unmap) {
            if (v > 1) {
                ans.emplace_back(k);
            }   
        }
        return ans;
    }
};