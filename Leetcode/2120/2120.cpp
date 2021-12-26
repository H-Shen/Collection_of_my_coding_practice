class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int r = startPos[0];
        int c = startPos[1];
        int m = (int)s.size();
        int r0,c0;
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int counter = 0;
            r0 = r;
            c0 = c;
            for (int j = i; j < m; ++j) {
                if (s[j] == 'L') {
                    --c0;
                }
                else if (s[j] == 'R') {
                    ++c0;
                }
                else if (s[j] == 'U') {
                    --r0;
                }
                else if (s[j] == 'D') {
                    ++r0;
                }
                if (r0 >= 0 && r0 < n && c0 >= 0 && c0 < n) {
                    ++counter;
                }
                else {
                    break;
                }
            }
            ans[i] = counter;
        }
        return ans;
    }
};