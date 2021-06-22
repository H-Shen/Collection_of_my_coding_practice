constexpr int MAXN = 3;

class Solution {
public:
    bool check(const vector<string> &board, char c) {
        // check rows
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == c) return true;
        if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == c) return true;
        if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == c) return true;
        // check cols
        if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == c) return true;
        if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == c) return true;
        if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == c) return true;
        // check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == c) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == c) return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int counter1 = 0;
        int counter2 = 0;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                if (board[i][j] == 'X') {
                    ++counter1;
                }
                else if (board[i][j] == 'O') {
                    ++counter2;
                }
            }
        }
        if (counter1 >= counter2 && counter1 - counter2 <= 1) {
            if (check(board,'O') && check(board, 'X')) {
                return false;
            }
            else if (check(board,'O') && !check(board, 'X')) {
                return counter1 == counter2;
            }
            else if (!check(board,'O') && check(board, 'X')) {
                return counter1 - counter2 == 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};