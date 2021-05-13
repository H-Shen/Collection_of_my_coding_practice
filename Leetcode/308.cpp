using ll = long long;

template<ll N, ll D = 1>
class FenwickTree {
    vector<ll> tree;
    ll isum(ll ps) { return tree[ps]; }
    template<class... T>
    ll isum(ll ps, ll n, T... tail) {
        ll a = 0;
        while (n) {
            a += isum(ps * N + n, tail...);
            n -= (n & -n);
        }
        return a;
    }
    void iupd(ll u, ll ps) { tree[ps] += u; }
    template<class... T>
    void iupd(ll u, ll ps, ll n, T... tail) {
        while (n < N) {
            iupd(u, ps * N + n, tail...);
            n += (n & -n);
        }
    }
public:
    FenwickTree() : tree(pow(N, D)) {}
    template<class... T>
    ll sum(T... v) { return isum(0, v...); }
    template<class... T>
    void upd(ll u, T... v) { iupd(u, 0, v...); }
};

constexpr int MAXN = 305;
constexpr int DIMENSION = 2;

class NumMatrix {
private:
    FenwickTree<MAXN, DIMENSION> Tree;
    vector<vector<ll> > matrix;
public:
    NumMatrix(vector<vector<int>>& matrix_) {
        int n = (int)matrix_.size();
        int m = (int)matrix_.front().size();
        matrix.resize(n, vector<ll>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = matrix_[i][j];
                Tree.upd<ll>(matrix[i][j], i+1, j+1);
            }
        }
    }
    
    void update(int row, int col, int val) {
        ll original = matrix[row][col];
        ll diff = val - original;
        matrix[row][col] = val;
        Tree.upd<ll>(diff, row+1, col+1);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1; ++col1; ++row2; ++col2;
        if (row1 == 1 && col1 == 1) { return (int)Tree.sum<ll>(row2,col2); }
        else if (row1 == 1 && col1 != 1) { return (int)(Tree.sum<ll>(row2,col2)-Tree.sum<ll>(row2,col1-1));}
        else if (row1 != 1 && col1 == 1) { return (int)(Tree.sum<ll>(row2,col2)-Tree.sum<ll>(row1-1,col2));}
        return (int)(Tree.sum<ll>(row2,col2)-Tree.sum<ll>(row2,col1-1)-Tree.sum<ll>(row1-1,col2)+Tree.sum<ll>(row1-1,col1-1));
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */