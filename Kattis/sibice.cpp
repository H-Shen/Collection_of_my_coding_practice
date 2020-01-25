// https://open.kattis.com/problems/sibice

#include <bits/extc++.h>

using namespace std;

const double eps = 1e-8;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    int n, w, h;
    double l, hypot;
    cin >> n >> w >> h;
    hypot = sqrt((double) (w * w + h * h));

    for (int i = 0; i < n; ++i) {
        cin >> l;
        if (sgn(l - hypot) <= 0) {
            cout << "DA";
        } else {
            cout << "NE";
        }
        cout << endl;
    }

    return 0;
}
