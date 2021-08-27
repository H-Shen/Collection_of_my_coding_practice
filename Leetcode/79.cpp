constexpr int STEPS = 4;
constexpr int MAXN = 6*6;
const int dx[] = {0,0,1,-1};
const int dy[] = {-1,1,0,0};

class Solution {
public:
    bool ans;
    int n, m;
    void dfs(vector<vector<char>>& board, const string &word, bitset<MAXN> vis, int index, int i, int j) {
        if (ans) {
            return;
        }
        ++index;
        if (index == (int)word.size()) {
            ans = true;
            return;
        }
        int new_i,new_j;
        for (int step = 0; step < STEPS; ++step) {
            new_i = i+dx[step];
            new_j = j+dy[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board[new_i][new_j] == word[index]
               && !vis[new_i*m+new_j]) {
                vis[new_i*m+new_j] = true;
                dfs(board, word, vis, index, new_i, new_j);
                vis[new_i*m+new_j] = false;
            }
        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        ans = false;
        n = (int)board.size();
        m = (int)board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0] && !ans) {
                    bitset<MAXN> vis;
                    vis[i*m+j] = true;
                    dfs(board, word, vis, 0, i, j);
                }
            }
        }
        return ans;
    }
};