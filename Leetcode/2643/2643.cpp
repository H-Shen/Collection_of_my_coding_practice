class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            cnt[i] = (int)count(mat[i].begin(),mat[i].end(),1);
        }
        auto iter = max_element(cnt.begin(),cnt.end());
        return vector<int>{(int)(iter - cnt.begin()), *iter};
    }
};