class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {

        const int LEN = 9;
        const char EMPTYSLOT = '.';

        auto convert = [&](const vector<vector<char>> &board, int posX, int posY) {
            vector<char> tmp;
            for (int i = posX; i < posX + 3; ++i) {
                for (int j = posY; j < posY + 3; ++j) {
                    if (board[i][j] != EMPTYSLOT) {
                        tmp.push_back(board[i][j]);
                    }
                }
            }
            return tmp;
        };

        auto uniqueCheck = [](const vector<char> &a) {
            return unordered_set<char>(a.begin(), a.end()).size() == a.size();
        };

        //row
        for (const auto &i : board) {
            vector<char> tmp;
            for (const auto &j : i) {
                if (j != EMPTYSLOT) {
                    tmp.push_back(j);
                }
            }
            if (!uniqueCheck(tmp)) {
                return false;
            }
        }

        //col
        for (size_t i = 0; i < LEN; ++i) {
            vector<char> tmp;
            for (size_t j = 0; j < LEN; ++j) {
                if (board[j][i] != EMPTYSLOT) {
                    tmp.push_back(board[j][i]);
                }
            }
            if (!uniqueCheck(tmp)) {
                return false;
            }
        }

        //subBoard
        for (size_t i = 0; i <= 6; i += 3) {
            for (size_t j = 0; j <= 6; j += 3) {
                if (!uniqueCheck(convert(board, static_cast<int>(i), static_cast<int>(j)))) {
                    return false;
                }
            }
        }
        return true;
    }
};