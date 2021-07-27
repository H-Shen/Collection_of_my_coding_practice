constexpr int MAXN = 1e4+5;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        vector<int> ans(n*m);
        int anslength = 0;
        int new_i,new_j,val;
        bool direction = true;
        int temp[MAXN]{};
        int templength;
        for (int i = 0; i < n; ++i) {
            templength = 0;
            new_i = i;
            new_j = 0;
            try {
                while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    val = mat[new_i][new_j];
                    temp[templength++] = val;
                    --new_i;
                    ++new_j;
                }
            } catch (...) {}
            // down
            if (!direction) {
                for (int k = templength - 1; k >= 0; --k) {
                    ans[anslength++] = temp[k];
                }
                direction = true;
            }
            // up
            else {
                for (int k = 0; k < templength; ++k) {
                    ans[anslength++] = temp[k];
                }
                direction = false;
            }
        }
        for (int j = 1; j < m; ++j) {
            templength = 0;
            new_i = n-1;
            new_j = j;
            try {
                while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    val = mat[new_i][new_j];
                    temp[templength++] = val;
                    --new_i;
                    ++new_j;
                }
            } catch (...) {}
            // down
            if (!direction) {
                for (int k = templength - 1; k >= 0; --k) {
                    ans[anslength++] = temp[k];
                }
                direction = true;
            }
            // up
            else {
                for (int k = 0; k < templength; ++k) {
                    ans[anslength++] = temp[k];
                }
                direction = false;
            }
        }
        return ans;
    }
};