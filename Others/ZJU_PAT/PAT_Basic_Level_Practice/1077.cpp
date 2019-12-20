#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a < eps) return 0;
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j;

    int g2;
    double g1;
    int result, sum, tmp;

    for (i = 0; i < n; ++i) {
        scanf("%d", &g2);
        vector<int> tmpArr;
        for (j = 0; j < n - 1; ++j) {
            scanf("%d", &tmp);
            if (tmp >= 0 && tmp <= m) {
                tmpArr.push_back(tmp);
            }
        }
        auto it = minmax_element(tmpArr.begin(), tmpArr.end());
        sum = accumulate(tmpArr.begin(), tmpArr.end(), 0) - (*it.first) - (*it.second);
        g1 = (double) sum / (tmpArr.size() - 2);

        double tmpDouble = (g1 + (double) g2) / 2.0;

        if (sgn(tmpDouble - (int) tmpDouble - 0.5) >= 0) {
            result = (int) tmpDouble + 1;
        } else {
            result = (int) tmpDouble;
        }
        printf("%d\n", result);

    }
    return 0;
}