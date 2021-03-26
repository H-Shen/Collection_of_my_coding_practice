class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = (int)points.size();
        int smallestDist = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i)
            if (points[i][0] == x || points[i][1] == y)
                smallestDist = min(smallestDist, abs(points[i][0]-x)+abs(points[i][1]-y));
        for (int i = 0; i < n; ++i)
            if ((points[i][0] == x || points[i][1] == y) && abs(points[i][0]-x)+abs(points[i][1]-y) == smallestDist) return i;
        return -1;
    }
};