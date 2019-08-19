#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
const double EPS = 1e-8;
double a3, a2, a1, a0;

inline
int sgn(double a) {
    if (a < -EPS) return -1;
    if (a < EPS) return 0;
    return 1;
}

double f(const double &x) {
    return a3 * x * x * x + a2 * x * x + a1 * x + a0;
}

int main() {

    ios_base::sync_with_stdio(false);
    double a, b;
    double result = 0.0;
    double mid;
    cin >> a3 >> a2 >> a1 >> a0 >> a >> b;

    while (true) {
        if (sgn(f(a)) == 0) {
            result = a;
            break;
        } else if (sgn(f(b)) == 0) {
            result = b;
            break;
        }
        if (abs(a - b) < 0.01) {
            result = (a + b) / 2.0;
            break;
        }
        if (sgn(f(a) * f(b)) == -1) {
            mid = f((a + b) / 2.0);
            if (sgn(mid) == 0) {
                result = (a + b) / 2.0;
                break;
            } else if (sgn(mid * f(a)) == 1) {
                a = (a + b) / 2.0;
            } else if (sgn(mid * f(b)) == 1) {
                b = (a + b) / 2.0;
            }
        }
    }
    cout << fixed << setprecision(2) << result << endl;
    return 0;
}