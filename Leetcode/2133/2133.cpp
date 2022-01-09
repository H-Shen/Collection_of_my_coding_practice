class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        vector<int> vec(n);
        iota(vec.begin(),vec.end(),1);
        // rows
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                temp.emplace_back(matrix[i][j]);
            }
            sort(temp.begin(),temp.end());
            if (temp != vec) return false;
        }
        // cols
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                temp.emplace_back(matrix[j][i]);
            }
            sort(temp.begin(),temp.end());
            if (temp != vec) return false;
        }
        return true;
    }
};