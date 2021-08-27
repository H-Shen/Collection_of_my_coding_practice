class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = (int)mat.size();
        vector<pair<int, int> > soldier(n);
        for (int i = 0; i < n; ++i) {
            soldier[i].first = upper_bound(mat[i].begin(), mat[i].end(), 1, greater<>()) - mat[i].begin();
            soldier[i].second = i;
        }
        sort(soldier.begin(), soldier.end(), [](const pair<int,int> &l, const pair<int,int> &r) {
            if (l.first == r.first) return l.second < r.second;
            return l.first < r.first;
        });
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = soldier[i].second;
        }
        return result;
    }
};