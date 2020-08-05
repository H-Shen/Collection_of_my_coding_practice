#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using float128 = __float128;

struct Point {
    float128 x, y;
};

// Shoelace formula: to calculate the area of a simple polygon whose
// vertices are described by their Cartesian coordinates in the plane
inline
float128 shoelace(const vector<Point> &v) {
    float128 sum = 0.0;
    int n = static_cast<int>(v.size());
    for (int i = 0; i < n - 1; ++i) {
        sum += v.at(i).x * v.at(i + 1).y - v.at(i + 1).x * v.at(i).y;
    }
    sum += v.at(n - 1).x * v.at(0).y - v.at(0).x * v.at(n - 1).y;
    if (sum < 0) sum = -sum;
    return sum / 2.0;
}

int main() {

    int n;
    double b, x, y;
    scanf("%d %lf", &n, &b);
    vector<Point> A(n);
    for (auto &i : A) {
        scanf("%lf %lf", &x, &y);
        i.x = x;
        i.y = y;
    }
    printf("%.4lf\n", static_cast<double>(shoelace(A) * b));

    return 0;
}