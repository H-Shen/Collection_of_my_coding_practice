class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        constexpr int N = 8;
        int r = 0, c = 0;
        bool found = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board.at(i).at(j) == 'R') {
                    r = i;
                    c = j;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        int counter = 0;
        int cur_r, cur_c;
        // same row
        cur_r = r;
        // up
        cur_c = c;
        try {
            while (true) {
                --cur_c;
                if (board.at(cur_r).at(cur_c) == 'p') {
                    ++counter;
                    break;
                }
                else if (board.at(cur_r).at(cur_c) == 'B') {
                    break;
                }
            }
        } catch (...) {}
        // down
        cur_c = c;
        try {
            while (true) {
                ++cur_c;
                if (board.at(cur_r).at(cur_c) == 'p') {
                    ++counter;
                    break;
                }
                else if (board.at(cur_r).at(cur_c) == 'B') {
                    break;
                }
            }
        } catch (...) {}
        // same column
        cur_c = c;
        // left
        cur_r = r;
        try {
            while (true) {
                --cur_r;
                if (board.at(cur_r).at(cur_c) == 'p') {
                    ++counter;
                    break;
                }
                else if (board.at(cur_r).at(cur_c) == 'B') {
                    break;
                }
            }
        } catch (...) {}
        // right
        try {
            while (true) {
                ++cur_r;
                if (board.at(cur_r).at(cur_c) == 'p') {
                    ++counter;
                    break;
                }
                else if (board.at(cur_r).at(cur_c) == 'B') {
                    break;
                }
            }
        } catch (...) {}
        return counter;
    }
};