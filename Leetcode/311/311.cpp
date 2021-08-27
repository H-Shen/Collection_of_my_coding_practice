class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        
        int n = (int)mat1.size();
        int m = (int)mat1.front().size();
        int p = (int)mat2.front().size();
        vector<vector<int> > mat3(n, vector<int>(p));
        vector<pair<vector<int>, vector<int> > > v(m);
        
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < m; ++k) {
                if (mat1[i][k] != 0) {
                    v[k].first.emplace_back(i);
                }
            }
        }
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                if (mat2[k][j] != 0) {
                    v[k].second.emplace_back(j);
                }
            }
        }
        for (int k = 0; k < m; ++k) {
            for (const auto &i : v[k].first) {
                for (const auto &j : v[k].second) {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return mat3;
    }
};