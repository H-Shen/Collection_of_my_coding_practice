#include <bits/stdc++.h>

using namespace std;

const double eps = 10e-8;

inline int sgn(double a, double b = 0.0) {
    //a == b
    if (fabs(a - b) < eps) {
        return 0;
    }
    //a > b
    if (a - b > eps) {
        return 1;
    }
    //a < b
    return -1;
}

int main() {

    int n;
    cin >> n;
    while (n--) {
        double h, w, w0;
        cin >> h >> w;
        w0 = (h - 100.0) * 0.9 * 2;
        double diff = fabs(w - w0) - w0 * 0.1;

        int res = sgn(diff);
        if (res == -1) {
            cout << "You are wan mei!" << endl;
        } else if (sgn(w, w0) == 1) {
            cout << "You are tai pang le!" << endl;
        } else {
            cout << "You are tai shou le!" << endl;
        }
    }
    return 0;
}