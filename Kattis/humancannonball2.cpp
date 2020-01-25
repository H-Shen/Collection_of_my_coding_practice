// https://open.kattis.com/problems/humancannonball2
//
#include <bits/extc++.h>

using namespace std;
constexpr double g = 9.81;
constexpr double EPS = 1e-6;

inline static
int sgn(double x) {
    if (x > EPS) {
        return 1;
    }
    if (x > -EPS) {
        return 0;
    }
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    int N;
    double v0, theta, x1, h1, h2, y1, cos_theta, tan_theta;
    cin >> N;
    while (N--) {
        cin >> v0 >> theta >> x1 >> h1 >> h2;
        cos_theta = cos(theta * M_PI / 180.0);
        tan_theta = tan(theta * M_PI / 180.0);
        y1 = x1 * tan_theta - 0.5 * g * (x1 / (v0 * cos_theta)) * (x1 / (v0 * cos_theta));
        if (sgn(h2 - y1 - 1.0) >= 0 && sgn(y1 - h1 - 1.0) >= 0) {
            cout << "Safe" << endl;
        } else {
            cout << "Not Safe" << endl;
        }
    }

    return 0;
}
