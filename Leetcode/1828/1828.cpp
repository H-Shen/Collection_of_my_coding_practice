class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = (int)queries.size();
        vector<int> result(n);
        int m = (int)points.size();
        int x, y, r;
        for (int i = 0; i < n; ++i) {
            x = queries[i][0];
            y = queries[i][1];
            r = queries[i][2];
            for (int j = 0; j < m; ++j) {
                if ( (x-points[j][0])*(x-points[j][0])+(y-points[j][1])*(y-points[j][1]) <= r*r ) {
                    ++result[i];
                }
            }
        }
        return result;
    }
};