#include <bits/stdc++.h>

using namespace std;

const double eps = 10e-8;

inline int sgn(double a, double b) {
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

bool cmp(const double a, const double b) {
    return (sgn(a, b) == -1);
}

int main() {

    int n, k, m, i, pos;
    double s;
    cin >> n >> k >> m;
    vector<double> res(n);
    i = 0;
    pos = 0;
    while (n--) {

        vector<double> tmp(k);
        for (i = 0; i < k; ++i) {
            cin >> tmp[i];
        }
        sort(tmp.begin(), tmp.end(), cmp);
        s = (accumulate(tmp.begin(), tmp.end(), (double) 0) - tmp[0] - tmp[k - 1]) / (double) (k - 2);
        res[pos] = s;
        ++pos;
    }

    sort(res.begin(), res.end(), cmp);

    int len = res.size();
    for (i = len - m; i < len - 1; ++i) {
        printf("%.3f ", res[i]);
    }
    printf("%.3f\n", res[len - 1]);
    return 0;
}