class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if (mat.size() == 1) {
            return mat.front().front();
        }
        int n = (int)mat.size();
        vector<int> vec(mat.front());
        for (int i = 1; i < n; ++i) {
            vector<int> temp;
            set_intersection(vec.begin(), vec.end(), mat[i].begin(), mat[i].end(), back_inserter(temp));
            if (temp.empty()) {
                return -1;
            }
            vec = temp;
        }
        return vec.front();
    }
};