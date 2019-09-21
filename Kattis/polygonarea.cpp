// https://open.kattis.com/problems/polygonarea
//
#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x;
    double y;
    explicit Point(double a = 0, double b = 0) {
        x = a;
        y = b;
    }
};

double area_of_polygon(vector<Point>polygon) {
    int vcount = static_cast<int>(polygon.size());
    int i;
    double s;
    if (vcount < 3)
        return 0;
    s = polygon[0].y * (polygon[vcount - 1].x - polygon[1].x);
    for (i = 1; i < vcount; i++)
        s += polygon[i].y * (polygon[(i - 1)].x - polygon[(i + 1) % vcount].x);
    return s / 2;
}

int main() {

    int n, x, y;
    while (~scanf("%d", &n)) {
        if (n == 0) {
            break;
        }
        vector<Point> P(static_cast<size_t>(n));
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            P.at(i).x = x;
            P.at(i).y = y;
        }
        double area = area_of_polygon(P);
        if (area < 0) {
            printf("CW %.1f\n", -area);
        } else {
            printf("CCW %.1f\n", area);
        }
    }

    return 0;
}
