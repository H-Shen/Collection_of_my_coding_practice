// https://open.kattis.com/problems/spavanac

#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int h, m;
    cin >> h >> m;

    if (m >= 45) {
        m -= 45;
    } else {
        if (h == 0) {
            h = 23;
            m = m + 60 - 45;
        } else {
            --h;
            m = m + 60 - 45;
        }
    }
    cout << h << ' ' << m << endl;

    return 0;
}
