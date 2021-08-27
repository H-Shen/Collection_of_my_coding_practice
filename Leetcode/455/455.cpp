class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int counter = 0;
        int n = (int)g.size();
        int m = (int)s.size();
        for (int i = 0, j = 0; i < m; ++i) {
            if (j >= n) {
                break;
            }
            if (s[i] >= g[j]) {
                ++counter;
                ++j;
            }
            else if (s[i] < g[j]) {
                continue;
            }
        }
        return counter;
    }
};