constexpr int MINN = 3;
constexpr int SIDES = 55;

class Solution {
public:
    int n, m;
    bitset<SIDES> vis[SIDES];
    tuple<int,int,int> checkVertical(const vector<vector<int>>& board, int i, int j) {
        tuple<int,int,int> p;
        int new_i,new_j;
        // up
        new_i = i;
        new_j = j;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board[new_i][new_j] == board[i][j]) {
            vis[new_i][new_j] = true;
            --new_i;
        }
        if (new_i == i) {
            get<0>(p) = i;
        } else {
            get<0>(p) = new_i+1;
        }
        // down
        new_i = i;
        new_j = j;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board[new_i][new_j] == board[i][j]) {
            vis[new_i][new_j] = true;
            ++new_i;
        }
        if (new_i == i) {
            get<1>(p) = i;
        } else {
            get<1>(p) = new_i-1;
        }
        get<2>(p) = j;
        return p;
    }
    tuple<int,int,int> checkHorizontal(const vector<vector<int>>& board, int i, int j) {
        tuple<int,int,int> p;
        int new_i,new_j;
        // left
        new_i = i;
        new_j = j;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board[new_i][new_j] == board[i][j]) {
            vis[new_i][new_j] = true;
            --new_j;
        }
        if (new_j == j) {
            get<0>(p) = j;
        } else {
            get<0>(p) = new_j+1;
        }
        // right
        new_i = i;
        new_j = j;
        while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board[new_i][new_j] == board[i][j]) {
            vis[new_i][new_j] = true;
            ++new_j;
        }
        if (new_j == j) {
            get<1>(p) = j;
        } else {
            get<1>(p) = new_j-1;
        }
        get<2>(p) = i;
        return p;
    }
    // falling from right to left
    vector<int> gravityFalling(const vector<int> &v) {
        int length = (int)v.size();
        vector<int> result(length);
        int j = 0;
        for (int i = 0; i < length; ++i) {
            if (v[i] != 0) {
                result[j] = v[i];
                ++j;
            }
        }
        for (; j < length; ++j) {
            result[j] = 0;
        }
        return result;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        n = (int)board.size();
        m = (int)board.front().size();
        
        while (true) {
            // reset before checking
            for (int i = 0; i < SIDES; ++i) {
                vis[i].reset();
            }
            // check Vertical
            vector<tuple<int,int,int> > toClean1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] != 0 && !vis[i][j]) {
                        auto p = checkVertical(board, i, j);
                        if (get<1>(p) - get<0>(p) + 1 >= MINN) {
                            toClean1.emplace_back(p);
                        }
                    }
                }
            }
            // reset before checking
            for (int i = 0; i < SIDES; ++i) {
                vis[i].reset();
            }
            // check Horizontal
            vector<tuple<int,int,int> > toClean2;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] != 0 && !vis[i][j]) {
                        auto p = checkHorizontal(board, i, j);
                        if (get<1>(p) - get<0>(p) + 1 >= MINN) {
                            toClean2.emplace_back(p);
                        }
                    }
                }
            }
            if (toClean1.empty() && toClean2.empty()) {
                break;
            }
            // clean Vertical
            for (const auto &[l,r,j] : toClean1) {
                for (int i = l; i <= r; ++i) {
                    board[i][j] = 0;
                }
            }
            // clean Horizontal
            for (const auto &[l,r,i] : toClean2) {
                for (int j = l; j <= r; ++j) {
                    board[i][j] = 0;
                }
            }
            
            // simulate the gravity
            for (int i = 0; i < m; ++i) {
                vector<int> temp(n);
                for (int j = 0; j < n; ++j) {
                    temp[j] = board[n-j-1][i];
                }
                vector<int> temp2 = gravityFalling(temp);
                for (int j = 0; j < n; ++j) {
                    board[n-j-1][i] = temp2[j];
                }
            }
        }
        
        return board;
    }
};