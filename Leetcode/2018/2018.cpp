class Solution {
public:
    bool checkRows(vector<vector<char>>& board, string& word, int start, int end, int row) {
        if (end-start+1 != (int)word.size()) {
            return false;
        }
        for (int i = start, j = 0; i <= end; ++i, ++j) {
            if (board[row][i] != ' ' && board[row][i] != word[j]) {
                return false;
            }
        }
        return true;
    }
    bool checkCols(vector<vector<char>>& board, string& word, int start, int end, int col) {
        if (end-start+1 != (int)word.size()) {
            return false;
        }
        for (int i = start, j = 0; i <= end; ++i, ++j) {
            if (board[i][col] != ' ' && board[i][col] != word[j]) {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, string& word) {
        int n = (int)board.size();
        int m = (int)board[0].size();
        // check rows
        for (int i = 0; i < n; ++i) {
            int start = -1;
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != '#') {
                    if (start == -1) {
                        start = j;
                    }
                } else {
                    if (start != -1) {
                        if (checkRows(board, word, start, j-1, i)) {
                            return true;
                        }
                        start = -1;
                    }
                }
            }
            if (start != -1) {
                if (checkRows(board, word, start, m-1, i)) {
                    return true;
                }
            }
        }
        // check cols
        for (int i = 0; i < m; ++i) {
            int start = -1;
            for (int j = 0; j < n; ++j) {
                if (board[j][i] != '#') {
                    if (start == -1) {
                        start = j;
                    }
                } else {
                    if (start != -1) {
                        if (checkCols(board, word, start, j-1, i)) {
                            return true;
                        }
                        start = -1;
                    }
                }
            }
            if (start != -1) {
                if (checkCols(board, word, start, n-1, i)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {  
        string wordRev(word);
        reverse(wordRev.begin(),wordRev.end());
        return solve(board, word) || solve(board, wordRev);
    }
};