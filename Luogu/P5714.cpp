#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const double eps = 1e-7;

int sgn(double x) {
    if (x > eps) return 1;
    if (x > -eps) return 0;
    return -1;
}

int main() {
    double m, h;
    cin >> m >> h;
    double p = m / (h * h);
    if (sgn(p - 18.5) < 0) {
        cout << "Underweight" << endl;
        return 0;
    }
    if (sgn(p - 24.0) >= 0) {
        cout << p << endl;
        cout << "Overweight" << endl;
        return 0;
    }
    cout << "Normal" << endl;
    return 0;
}

