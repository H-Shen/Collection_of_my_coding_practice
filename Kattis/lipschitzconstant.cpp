// https://open.kattis.com/problems/lipschitzconstant
//
#include <bits/extc++.h>

using namespace std;
using Point = pair<double, double>;
constexpr double EPS = 1e-6;

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}

bool cmp(const Point &lhs, const Point &rhs) {
    return sgn(lhs.first - rhs.first) < 0;
}

int main() {

    int n;
    scanf("%d", &n);
    vector<Point> A(n);
    for (auto &i : A) {
        scanf("%lf %lf", &i.first, &i.second);
    }
    sort(A.begin(), A.end(), cmp);

    // Use greedy to obtain the largest abs(slope)
    double L = -1.0;
    double temp;
    for (int i = 1; i < n; ++i) {
        temp = abs(A.at(i).second - A.at(i - 1).second) / abs(A.at(i).first - A.at(i - 1).first);
        if (sgn(L - temp) < 0) {
            L = temp;
        }
    }
    printf("%.6lf\n", L);

    return 0;
}
