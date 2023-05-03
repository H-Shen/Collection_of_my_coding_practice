class Solution {
public:
    inline
    bool check(vector<int>& arr, vector<pair<int,int>>& val2pos, int mid, int r, int c) {
        vector<vector<int>> vec(r, vector<int>(c));
        int r_, c_;
        for (int i = 0; i <= mid; ++i) {
            r_ = val2pos[arr[i]].first;
            c_ = val2pos[arr[i]].second;
            vec[r_][c_] = 1;
        }
        for (int i = 0; i < r; ++i) {
            if ((int)count(vec[i].begin(),vec[i].end(),1) == c) {
                return true;
            }
        }
        for (int i = 0; i < c; ++i) {
            int s = 0;
            for (int j = 0; j < r; ++j) {
                s += vec[j][i];
            }
            if (s == r) {
                return true;
            }
        }
        return false;
    }
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = (int)arr.size();
        vector<pair<int,int>> val2pos(n+1);
        int row = (int)mat.size();
        int col = (int)mat[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                val2pos[mat[i][j]].first = i;
                val2pos[mat[i][j]].second = j;
            }
        }
        int l = 0, r = n-1;
        int mid;
        int ans = numeric_limits<int>::max();
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check(arr, val2pos, mid, row, col)) {
                ans = min(ans, mid);
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};
