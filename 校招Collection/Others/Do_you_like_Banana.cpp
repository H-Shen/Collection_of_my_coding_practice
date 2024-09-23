// https://ac.nowcoder.com/acm/problem/14625

#include <bits/stdc++.h>

using namespace std;
constexpr double eps = 1e-10;

inline static
int sgn(double a) {
    if (a < -eps) return -1;
    if (a < eps) return 0;
    return 1;
}

struct Point {
    double x, y;

    Point(double a, double b) : x(a), y(b) {}
};

inline static
bool cmp(const double &a, const double &b) {
    return sgn(a - b) <= 0;
}

inline static
bool judge(Point a, Point b, Point c, Point d) {
    if (!(min(a.x, b.x, cmp) <= max(c.x, d.x, cmp) &&
          min(c.y, d.y, cmp) <= max(a.y, b.y, cmp) &&
          min(c.x, d.x, cmp) <= max(a.x, b.x, cmp) &&
          min(a.y, b.y, cmp) <= max(c.y, d.y, cmp)))
        return false;

    double u, v, w, z;
    u = (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
    v = (d.x - a.x) * (b.y - a.y) - (b.x - a.x) * (d.y - a.y);
    w = (a.x - c.x) * (d.y - c.y) - (d.x - c.x) * (a.y - c.y);
    z = (b.x - c.x) * (d.y - c.y) - (d.x - c.x) * (b.y - c.y);
    return (u * v <= eps && w * z <= eps);
}


int main() {
    int T;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (judge(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4))) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}