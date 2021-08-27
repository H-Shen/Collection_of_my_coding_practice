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
        int new_i,new_j;
        bool direction = true;
        int templength;
        for (int i = 0; i < n; ++i) {
            templength = 0;
            new_i = i;
            new_j = 0;
            try {
                while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    ans[anslength+templength] = mat[new_i][new_j];
                    ++templength;
                    --new_i;
                    ++new_j;
                }
            } catch (...) {}
            if (!direction) {
                reverse(ans.begin()+anslength, ans.begin()+anslength+templength);
            }
            anslength += templength;
            direction = !direction;
        }
        for (int j = 1; j < m; ++j) {
            templength = 0;
            new_i = n-1;
            new_j = j;
            try {
                while (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    ans[anslength+templength] = mat[new_i][new_j];
                    ++templength;
                    --new_i;
                    ++new_j;
                }
            } catch (...) {}
            if (!direction) {
                reverse(ans.begin()+anslength, ans.begin()+anslength+templength);
            }
            anslength += templength;
            direction = !direction;
        }
        return ans;
    }
};