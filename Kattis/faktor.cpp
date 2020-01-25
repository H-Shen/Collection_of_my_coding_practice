// https://open.kattis.com/problems/faktor
#include <bits/extc++.h>

using namespace std;
double eps = 1e-9;

inline
int sgn(double a) {
    if (a > eps) {
        return 1;
    } else if (a < -eps) {
        return -1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int a, i;
    double tmp;

    cin >> a >> i;
    int val = a * i;
    while (true) {
        tmp = val * 1.0 / a;
        if (sgn(tmp - 1.0 * (i - 1)) > 0) {
            --val;
        } else {
            ++val;
            break;
        }
    }
    cout << val << endl;
    return 0;
}
