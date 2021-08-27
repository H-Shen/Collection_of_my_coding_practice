class TicTacToe {
private:
    int n;
    vector<int> rowPlayer1, colPlayer1;
    int leftDiagonalPlayer1, rightDiagonalPlayer1;
    vector<int> rowPlayer2, colPlayer2;
    int leftDiagonalPlayer2, rightDiagonalPlayer2;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n) {
        rowPlayer1.resize(n);
        colPlayer1.resize(n);
        leftDiagonalPlayer1 = 0;
        rightDiagonalPlayer1 = 0;
        
        rowPlayer2.resize(n);
        colPlayer2.resize(n);
        leftDiagonalPlayer2 = 0;
        rightDiagonalPlayer2 = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            rowPlayer1[row]++;
            colPlayer1[col]++;
            if (row == col) {
                leftDiagonalPlayer1++;
            }
            if (row + col == n - 1) {
                rightDiagonalPlayer1++;
            }
            if (rowPlayer1[row] == n || colPlayer1[col] == n || leftDiagonalPlayer1 == n || rightDiagonalPlayer1 == n) {
                return player;
            }
            return 0;
        }
        else {
            rowPlayer2[row]++;
            colPlayer2[col]++;
            if (row == col) {
                leftDiagonalPlayer2++;
            }
            if (row + col == n - 1) {
                rightDiagonalPlayer2++;
            }
            if (rowPlayer2[row] == n || colPlayer2[col] == n || leftDiagonalPlayer2 == n || rightDiagonalPlayer2 == n) {
                return player;
            }
            return 0;
        }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */