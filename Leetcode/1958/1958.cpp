class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        constexpr int STEPS = 8;
        constexpr int N = 8;
        const int dx[] = {0,0,1,-1,1,1,-1,-1};
        const int dy[] = {1,-1,0,0,-1,1,-1,1};
        int newR, newC;
        bool flag;
        for (int step = 0; step < STEPS; ++step) {
            newR = rMove + dx[step];
            newC = cMove + dy[step];
            if (newR >= 0 && newR < N && newC >= 0 && newC < N) {
                if (color == 'B' && board[newR][newC] == 'W') {
                    flag = false;
                    while (true) {
                        newR += dx[step];
                        newC += dy[step];
                        if (!(newR >= 0 && newR < N && newC >= 0 && newC < N)) {
                            break;
                        }
                        if (board[newR][newC] == 'B') {
                            flag = true;
                            break;
                        }
                        else if (board[newR][newC] == '.') {
                            break;
                        }
                    }
                    if (flag) {
                        return true;
                    }
                }
                else if (color == 'W' && board[newR][newC] == 'B') {
                    flag = false;
                    while (true) {
                        newR += dx[step];
                        newC += dy[step];
                        if (!(newR >= 0 && newR < N && newC >= 0 && newC < N)) {
                            break;
                        }
                        if (board[newR][newC] == 'W') {
                            flag = true;
                            break;
                        }
                        else if (board[newR][newC] == '.') {
                            break;
                        }
                    }
                    if (flag) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};