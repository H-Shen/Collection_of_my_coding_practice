#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 3;
char shape_type[MAXN];

constexpr double EPS = 1e-7;

inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

struct Circle {
    double x, y, r;

    explicit Circle(double x, double y, double r) : x(x), y(y), r(r) {}

    [[nodiscard]] bool inside(double x0, double y0) const {
        return sgn(sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0)) - r) < 0;
    }
};
struct Rectangle {
    double x1, y1, x2, y2;

    explicit Rectangle(double x1, double y1, double x2, double y2) : x1(x1),
                                                                     y1(y1),
                                                                     x2(x2),
                                                                     y2(y2) {}
    [[nodiscard]] bool inside(double x0, double y0) const {
        auto [min_x, max_x] = minmax(x1, x2);
        auto [min_y, max_y] = minmax(y1, y2);
        return (sgn(x0 - min_x) > 0 && sgn(x0 - max_x) < 0 &&
                sgn(y0 - min_y) > 0 && sgn(y0 - max_y) < 0);
    }
};

int main() {

    int n, m;
    double x1, y1, x2, y2, r, x, y;
    scanf("%d %d", &n, &m);
    vector<Circle> circles;
    vector<Rectangle> rectangles;
    while (n--) {
        scanf("%s", shape_type);
        if (strcmp(shape_type, "c") == 0) {
            scanf("%lf %lf %lf", &x, &y, &r);
            circles.emplace_back(Circle(x, y, r));
        } else {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            rectangles.emplace_back(Rectangle(x1, y1, x2, y2));
        }
    }
    vector<pair<double, double> > Points;
    for (int i = 0; i < m; ++i) {
        scanf("%lf %lf", &x, &y);
        Points.emplace_back(make_pair(x, y));
    }
    vector<int> stats(m);
    for (int i = 0; i < m; ++i) {
        for (const auto &j : circles) {
            if (j.inside(Points.at(i).first, Points.at(i).second)) {
                ++stats.at(i);
            }
        }
        for (const auto &j : rectangles) {
            if (j.inside(Points.at(i).first, Points.at(i).second)) {
                ++stats.at(i);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", stats.at(i));
    }
    return 0;
}
