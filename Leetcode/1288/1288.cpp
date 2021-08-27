class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        vector<bool> inDegree(n);
        int a, b, c, d;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    a = intervals[i][0];
                    b = intervals[i][1];
                    c = intervals[j][0];
                    d = intervals[j][1];
                    if (c <= a && b <= d) {
                        inDegree[i] = true;
                    }
                }
            }
        }
        return count(inDegree.begin(), inDegree.end(), false);
    }
};