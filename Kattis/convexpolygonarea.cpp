// https://open.kattis.com/problems/convexpolygonarea
//
#include <bits/stdc++.h>

using namespace std;

// x for real, y for image
using PX = complex<double>;

// cross product
inline static
double cp(const PX &a, const PX &b) {
    return (conj(a) * b).imag();
}

double area(vector<PX> const &P) {
    double a = 0.0;
    int len = static_cast<int>(P.size());
    for (int i = 0; i < len; i++)
        a += cp(P[i], P[(i + 1) % len]);
    return 0.5 * fabs(a);
}

int main() {

    ios_base::sync_with_stdio(false);
    int n, m, x, y;
    cin >> n;
    while (n--) {
        cin >> m;
        vector<PX> P(static_cast<size_t>(m));
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            P.at(i).real(x);
            P.at(i).imag(y);
        }
        cout << area(P) << endl;
    }

    return 0;
}
