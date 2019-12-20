// https://www.nowcoder.com/practice/cac8bc877bbd444c8999d7fd77e5dd89?tpId=49

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;

inline int sgn(double a) {
    if (a < -EPS) {
        return -1;
    }
    if (a < EPS) {
        return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, x, y, t, i, j;
    while (cin >> n >> m >> x >> y >> t) {
        vector<vector<double> > A(n);
        for (auto &p : A) {
            p.resize(m);
        }
        double cc = 0.0, ss = 0.0;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                cin >> A.at(i).at(j);
                ss = ss + A.at(i).at(j);
            }
        }

        cc = A.at(x - 1).at(y - 1);
        cc = 1 - pow(1 - cc, t);

        ss = ss / (n * m);
        ss = 1 - pow(1 - ss, t);

        int cmp = sgn(cc - ss);

        cout << fixed << setprecision(2);
        if (cmp == 0) {
            cout << "equal" << endl;
            cout << ss << endl;
        } else if (cmp == 1) {
            cout << "cc" << endl;
            cout << cc << endl;
        } else {
            cout << "ss" << endl;
            cout << ss << endl;
        }
    }
    return 0;
}