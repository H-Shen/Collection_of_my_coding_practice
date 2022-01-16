class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = (int)s.size();
        vector<string> ans;
        string str;
        for (int i = 0; i < n; ++i) {
            if ((int)str.size() == k) {
                ans.emplace_back(str);
                str.clear();
                str.push_back(s[i]);
            }
            else {
                str.push_back(s[i]);
            }
        }
        if (!str.empty()) {
            while ((int)str.size() < k) {
                str.push_back(fill);
            }
            ans.emplace_back(str);
        }
        return ans;
    }
};