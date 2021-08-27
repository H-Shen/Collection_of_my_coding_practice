class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if (mat.empty()) return mat;
        if (mat.front().empty()) return mat;
        int n = (int)mat.size();
        int m = (int)mat.front().size();
        for (int j = 0; j < m; ++j) {
            vector<int> vec;
            int cur_i = 0;
            int cur_j = j;
            try {
                while (true) {
                    vec.emplace_back(mat.at(cur_i).at(cur_j));
                    ++cur_i;
                    ++cur_j;
                }
            } catch (...) {}
            sort(vec.begin(), vec.end());
            auto iter = vec.begin();
            cur_i = 0;
            cur_j = j;
            try {
                while (true) {
                    if (iter == vec.end()) break;
                    mat.at(cur_i).at(cur_j) = *iter;
                    ++iter;
                    ++cur_i;
                    ++cur_j;
                }
            } catch (...) {}
        }
        for (int i = 0; i < n; ++i) {
            vector<int> vec;
            int cur_i = i;
            int cur_j = 0;
            try {
                while (true) {
                    vec.emplace_back(mat.at(cur_i).at(cur_j));
                    ++cur_i;
                    ++cur_j;
                }
            } catch (...) {}
            sort(vec.begin(), vec.end());
            auto iter = vec.begin();
            cur_i = i;
            cur_j = 0;
            try {
                while (true) {
                    if (iter == vec.end()) break;
                    mat.at(cur_i).at(cur_j) = *iter;
                    ++iter;
                    ++cur_i;
                    ++cur_j;
                }
            } catch (...) {}
        }
        return mat;
    }
};