// https://open.kattis.com/problems/speed
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-8;
static double upperBound = 1e7;
static double lowerBound;

inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int n;
double t;

inline static
int solve(const vector<pair<double, double> > &A, double x) {
    double sum = 0.0;
    for (const auto &i : A) {
        sum += i.first / (x + i.second);
    }
    return sgn(sum - t);
}

inline static
double get_min_x(const vector<pair<double, double> > &A) {
    double ret = -upperBound;
    for (const auto &i : A) {
        ret = max(ret, -i.second);
    }
    return ret;
}

int main() {

    scanf("%d %lf", &n, &t);
    vector<pair<double, double> > A(n);
    for (auto &i : A) {
        scanf("%lf %lf", &i.first, &i.second);
    }
    lowerBound = get_min_x(A);
    double middle;
    int temp;
    while (true) {
        if (sgn(lowerBound - upperBound) >= 0) {
            break;
        }
        middle = (lowerBound + upperBound) / 2;
        temp = solve(A, middle);
        if (temp < 0) {
            upperBound = middle;
        } else if (temp > 0) {
            lowerBound = middle;
        } else {
            break;
        }
    }
    printf("%.8lf\n", (lowerBound + upperBound) / 2);
    return 0;
}

