#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;
inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

double a, b, c, d, A, B, C, delta, x1, x2, x3, K, T, zeta;

int main() {

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    A = b*b-3*a*c;
    B = b*c-9*a*d;
    C = c*c-3*b*d;
    delta = B*B-4*A*C;
    if (sgn(A) == 0 && sgn(B) == 0) {
        x1 = -b / (3*a);
        x2 = x1;
        x3 = x1;
    }
    else if (sgn(delta) > 0) {
        // Impossible, since we are told that 3 roots are real number
    }
    else if (sgn(delta) == 0) {
        K = B / A;
        x1 = -b / a + K;
        x2 = -K / 2;
        x3 = x2;
    }
    else {
        T = (2.0*A*b-3.0*a*B) / (2.0*pow(A, 3.0/2.0));
        zeta = acos(T);
        x1 = (-b - 2*sqrt(A)*cos(zeta/3.0))/(3.0*a);
        x2 = (-b+sqrt(A)*(cos(zeta/3.0)+sqrt(3)*sin(zeta/3.0)))/(3.0*a);
        x3 = (-b+sqrt(A)*(cos(zeta/3.0)-sqrt(3)*sin(zeta/3.0)))/(3.0*a);
    }
    vector<double> output = {x1, x2, x3};
    sort(output.begin(), output.end());
    printf("%.2lf %.2lf %.2lf\n", output.at(0), output.at(1), output.at(2));

    return 0;
}
