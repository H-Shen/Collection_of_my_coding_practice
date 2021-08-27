namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        constexpr int STEPS = 4;
        constexpr int dx[] = {-1, 1, 0, 0};
        constexpr int dy[] = {0, 0, -1, 1};
        int n = (int)board.size();
        int m = (int)board.front().size();
        DSU::init(n * m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board.at(i).at(j) == 'O') {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && board.at(new_i).at(new_j) == 'O') {
                            DSU::merge(new_i * m + new_j, i * m + j);
                        }
                    }
                }
            }
        }
        unordered_set<int> groupsTouchEdge;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board.at(i).at(j) == 'O') {
                    groupsTouchEdge.insert(DSU::find(i * m + j));
                }
            }
        }
        // flipping
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board.at(i).at(j) == 'O' && groupsTouchEdge.find(DSU::find(i * m + j)) == groupsTouchEdge.end()) {
                    board.at(i).at(j) = 'X';
                }
            }
        }
    }
};