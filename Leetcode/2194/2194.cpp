class Solution {
public:
    vector<string> cellsInRange(string s) {
        int c1 = s[0] - 'A';
        int r1 = s[1] - '0';
        int c2 = s[3] - 'A';
        int r2 = s[4] - '0';
        vector<string> ans;
        string str;
        for (int c = c1; c <= c2; ++c) {
            for (int r = r1; r <= r2; ++r) {
                str.clear();
                str.push_back(c + 'A');
                str.push_back(r + '0');
                ans.emplace_back(str);
            }
        }
        return ans;
    }
};