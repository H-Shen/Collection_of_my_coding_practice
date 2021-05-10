class Solution {
public:
    bool check(const vector<vector<char>> &M, int c, int r, int n) {
        for (int i = 0; i < n; ++i) {
            if (M[i][c] == 'B') {
                if (M[i] != M[r]) {
                    return false;
                }
            }
        }
        return true;
    }
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int n = (int)picture.size();
        int m = (int)picture.front().size();
        vector<int> rows(n);
        for (int i = 0; i < n; ++i) {
            rows[i] = count(picture[i].begin(), picture[i].end(), 'B');
        }
        vector<int> cols(m);
        int counter;
        for (int i = 0; i < m; ++i) {
            counter = 0;
            for (int j = 0; j < n; ++j) {
                if (picture[j][i] == 'B') {
                    ++counter;
                }
            }
            cols[i] = counter;
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B' && rows[i] == target && cols[j] == target && check(picture, j, i, n)) {
                    ++answer;
                }
            }
        }
        return answer;
    }
};