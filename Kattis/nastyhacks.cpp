// https://open.kattis.com/problems/nastyhacks
#include <bits/extc++.h>

using namespace std;

const double eps = 1e-8;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, r, e, c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r >> e >> c;
        if (e - c > r) cout << "advertise" << endl;
        else if (e - c == r) cout << "does not matter" << endl;
        else cout << "do not advertise" << endl;
    }
    return 0;
}
