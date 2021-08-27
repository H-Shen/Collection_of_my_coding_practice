namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
    }
    void reset() {
        iota(father.begin(),father.end(),0);
        fill(Size.begin(),Size.end(),1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x,y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

class Solution {
public:
    vector<vector<int>> A;
    int n, m;
    bool check(const vector<vector<int>> &cells, int mid) {
        constexpr int STEPS = 2;
        const int dx[] = {0,1};
        const int dy[] = {1,0};
        for (int i = 0; i <= mid; ++i) {
            A[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        int new_i,new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] == 0) {
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i+dx[step];
                        new_j = j+dy[step];
                        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && A[new_i][new_j] == 0) {
                            DSU::merge(i*m+j,new_i*m+new_j);
                        }
                    }
                }
            }
        }
        bool ans = false;
        unordered_set<int> unset;
        for (int j = 0; j < m; ++j) {
            if (A[0][j] == 0) {
                unset.insert(DSU::find(0*m+j));
            }
        }
        if (!unset.empty()) {
            for (int j = 0; j < m; ++j) {
                if (A[n-1][j] == 0 && unset.find(DSU::find((n-1)*m+j)) != unset.end()) {
                    ans = true;
                    break;
                }
            }
        }
        DSU::reset();
        for (int i = 0; i < n; ++i) {
            fill(A[i].begin(),A[i].end(),0);
        }
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row;
        m = col;
        DSU::init(n*m);
        A.resize(n, vector<int>(m));
        int ret = 0;
        int l = 0;
        int r = (int)cells.size()-1;
        int mid;
        while (l <= r) {
            mid = l+((r-l)>>1);
            if (check(cells, mid)) {
                ret = max(ret, mid);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ret+1;
    }
};