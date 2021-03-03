class Solution {
public:
    bool collinear(int a, int b, int x, int y, int m, int n) {
        return (n-b)*(x-m) == (y-n)*(m-a);
    }
    double dist(int a, int b, int x, int y) {
        return sqrt((a-x)*(a-x)+(b-y)*(b-y));
    }
    double area(int a, int b, int x, int y, int m, int n) {
        double e0 = dist(a, b, x, y);
        double e1 = dist(a, b, m, n);
        double e2 = dist(x, y, m, n);
        double p = (e0+e1+e2)/2.0;
        return sqrt(p*(p-e0)*(p-e1)*(p-e2));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        int n = (int)points.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i+1; j < n - 1; ++j) {
                for (int k = j+1; k < n; ++k) {
                    ans = max(ans, area(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
                }
            }
        }
        return ans;
    }
};