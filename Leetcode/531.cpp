class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = (int)picture.size();
        int m = (int)picture.front().size();
        vector<int> rows(n);
        for (int i = 0; i < n; ++i) {
            rows[i] = count(picture[i].begin(), picture[i].end(), 'W');
        }
        vector<int> cols(m);
        for (int i = 0; i < m; ++i) {
            int counter = 0;
            for (int j = 0; j < n; ++j) {
                if (picture[j][i] == 'W') {
                    ++counter;
                }
            }
            cols[i] = counter;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B') {
                    if (rows[i] == m - 1 && cols[j] == n - 1) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};