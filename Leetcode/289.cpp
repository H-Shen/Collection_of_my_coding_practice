class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        constexpr int STEPS = 8;
        const int dx[] = {-1,1,-1,1,0,0,-1,1};
        const int dy[] = {1,-1,-1,1,1,-1,0,0};
        auto p = board;
        int countLives;
        int n = (int)board.size();
        int m = (int)board[0].size();
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                countLives = 0;
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && p[new_i][new_j] == 1) {
                        ++countLives;
                    }
                }
                if (p[i][j] == 0) {
                    if (countLives == 3) {
                        board[i][j] = 1;
                    }
                }
                else {
                    if (countLives < 2 || countLives > 3) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};