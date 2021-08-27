namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (x != father[x]) father[x] = find(father[x]);
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
    int numEnclaves(vector<vector<int>>& A) {
        constexpr int STEPS = 4;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        int n = (int)A.size();
        int m = (int)A.front().size();
        DSU::init(n * m);
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] == 1) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && A[new_i][new_j] == 1) {
                            DSU::merge(i*m+j,new_i*m+new_j);
                        }
                    }
                }
            }
        }
        unordered_set<int> boundary_id;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && A[i][j] == 1) {
                    boundary_id.insert(DSU::find(i*m+j));
                } 
            }
        }
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] == 1) {
                    int ancestor = DSU::find(i*m+j);
                    if (boundary_id.find(ancestor) == boundary_id.end()) {
                        ++counter;
                    }
                }
            }
        }
        return counter;
    }
};