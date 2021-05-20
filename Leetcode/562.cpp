class Solution {
public:
    int f(const vector<int>& A) {
        int ans = 0;
        int startIndex = -1;
        int endIndex = -1;
        int n = (int)A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1) {
                if (endIndex == -1) {
                    startIndex = i;
                    endIndex = i;
                }
                else {
                    ++endIndex;
                }
            } else {
                if (endIndex != -1) {
                    ans = max(ans, endIndex - startIndex + 1);
                    startIndex = -1;
                    endIndex = -1;
                }
            }
        }
        if (endIndex != -1) {
            ans = max(endIndex - startIndex + 1, ans);
        }
        return ans;
    }
    int longestLine(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        int ans = 0;
        //
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f(mat[i]));
        }
        //
        for (int j = 0; j < m; ++j) {
            vector<int> temp(n);
            for (int i = 0; i < n; ++i) {
                temp[i] = mat[i][j];
            }
            ans = max(ans, f(temp));
        }
        //
        for (int i = 0, j = 0; i < n; ++i) {
            vector<int> temp;
            int new_i = i;
            int new_j = j;
            try {
                while (true) {
                    temp.emplace_back(mat.at(new_i).at(new_j));
                    ++new_i;
                    ++new_j;
                }
            } catch (...) {}
            ans = max(ans, f(temp));
        }
        for (int i = 0, j = 0; j < m; ++j) {
            vector<int> temp;
            int new_i = i;
            int new_j = j;
            try {
                while (true) {
                    temp.emplace_back(mat.at(new_i).at(new_j));
                    ++new_i;
                    ++new_j;
                }
            } catch (...) {}
            ans = max(ans, f(temp));
        }
        //
        for (int i = 0, j = m-1; j >= 0; --j) {
            vector<int> temp;
            int new_i = i;
            int new_j = j;
            try {
                while (true) {
                    temp.emplace_back(mat.at(new_i).at(new_j));
                    ++new_i;
                    --new_j;
                }
            } catch (...) {}
            ans = max(ans, f(temp));
        }
        for (int i = 0, j = m-1; i < n-1; ++i) {
            vector<int> temp;
            int new_i = i;
            int new_j = j;
            try {
                while (true) {
                    temp.emplace_back(mat.at(new_i).at(new_j));
                    ++new_i;
                    --new_j;
                }
            } catch (...) {}
            ans = max(ans, f(temp));
        }
        return ans;
    }
};