// https://open.kattis.com/problems/sok
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int a, b, c, i, j, k;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &i, &j, &k);
    int s = i + j + k;
    double L = min(s * a * 1.0 / i, min(s * b * 1.0 / j, s * c * 1.0 / k));
    double x1 = L * i / s;
    double x2 = L * j / s;
    double x3 = L * k / s;
    printf("%.6lf %.6lf %.6lf\n", a*1.0-x1, b*1.0-x2, c*1.0-x3);
    return 0;
}
