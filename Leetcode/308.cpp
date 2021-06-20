using ll = long long;

template<typename T>
struct BIT_2D {
    vector<vector<T> > t;
    T lowbit(T i) {
        return i & (-i);
    }
    int N, M;
    // index starts from 1
    BIT_2D() = default;
    BIT_2D(int n, int m) : N(n), M(m) {
        t.resize(N+1, vector<T>(M+1));
    }
    // add 'val'
    void upd(int x, int y, T val) {
        for (int i = x; i <= N; i += lowbit(i)) {
            for (int j = y; j <= M; j += lowbit(j)) {
                t[i][j] += val;
            }
        }
    }
    void rupd(int x1, int y1, int x2, int y2, T val) {
        upd(x1, y1, val);
        upd(x1, y2+1, -val);
        upd(x2, y1+1, -val);
        upd(x2+1, y2+1, val);
    }
    // rangesum from [1][1] to [x][y]
    T sum(int x, int y) {
        T ans(0);
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                ans += t[i][j];
            }
        }
        return ans;
    }
    T rsum(int x1, int y1, int x2, int y2) {
        return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
    }
};

class NumMatrix {
private:
    vector<vector<int> > mat;
    BIT_2D<int> bit2d;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        mat = matrix;
        bit2d.N = n;
        bit2d.M = m;
        bit2d.t.resize(n+1);
        for (auto &i : bit2d.t) {
            i.resize(m+1);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bit2d.upd(i+1,j+1,mat[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - mat[row][col];
        bit2d.upd(row+1,col+1,diff);
        mat[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return bit2d.rsum(row1+1,col1+1,row2+1,col2+1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */