// https://open.kattis.com/problems/vacuumba
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, segment;
    double x, y, distance, theta, direction;
    cin >> n;
    for (int kase = 0; kase < n; ++kase) {
        cin >> segment;
        x = 0.0;
        y = 0.0;
        direction = 90.0;
        for (int i = 0; i < segment; ++i) {
            cin >> theta >> distance;
            direction += theta;
            x += distance * cos(M_PI / 180 * direction);
            y += distance * sin(M_PI / 180 * direction);
        }
        printf("%.5lf %.5lf\n", x, y);
    }

    return 0;
}
