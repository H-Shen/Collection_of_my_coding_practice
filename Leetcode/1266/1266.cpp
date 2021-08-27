class Solution {
public:
    int dist(int x0, int y0, int x1, int y1) {
        if (x0 == x1) {
            return abs(y0 - y1);
        }
        if (y0 == y1) {
            return abs(x0 - x1);
        }
        return max(abs(y0 - y1), abs(x0 - x1));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        if (n == 1) return 0;
        int time = 0;
        int cur_x = points[0][0];
        int cur_y = points[0][1];
        for (int i = 1; i < n; ++i) {
            time += dist(cur_x, cur_y, points[i][0], points[i][1]);
            cur_x = points[i][0];
            cur_y = points[i][1];
        }
        return time;
    }
};