// https://ac.nowcoder.com/acm/contest/249/A

#include <bits/stdc++.h>

using namespace std;

int main() {

    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    // SHENG JIN FORMULA, the 3rd situation
    double A = b*b - 3*a*c;
    double B = b*c - 9*a*d;
    double t = (2*A*b - 3*a*B) / (2*A*sqrt(A));
    auto theta = acos(t);

    double x1 = (-b + sqrt(A)*(cos(theta / 3) + sqrt(3)*sin(theta / 3))) / (3.0 * a);
    double x2 = (-b + sqrt(A)*(cos(theta / 3) - sqrt(3)*sin(theta / 3))) / (3.0 * a);
    double x3 = (-b - 2.0*sqrt(A)*cos(theta / 3)) / (3.0 * a);
    vector<double> L {x1, x2, x3};
    sort(L.begin(), L.end());
    printf("%.2lf %.2lf %.2lf\n", L[0], L[1], L[2]);
    return 0;

}