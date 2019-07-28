// https://www.nowcoder.com/practice/06a571f131424c2dbfb2195030c630da

#include <bits/stdc++.h>

using namespace std;
constexpr double eps = 1e-6;

inline int sgn(double a) {
    if (a < -eps) {
        return -1;
    }
    if (a < eps) {
        return 0;
    }
    return 1;
}

bool cmp(const pair<int, double> &a, const pair<int, double> &b) {
    double tmp_a = a.second / static_cast<double>(a.first);
    double tmp_b = b.second / static_cast<double>(b.first);
    return (sgn(tmp_a - tmp_b) > 0);
}

int main() {
    int m, n;
    double val;
    while (true) {
        scanf("%d %d", &m, &n);
        if (m == n && m == 0) {
            break;
        }
        val = 0.0;
        vector<pair<int, double> > A(static_cast<unsigned long>(m));
        for (auto &i : A) {
            scanf("%d %lf", &i.first, &i.second);
        }
        sort(A.begin(), A.end(), cmp);
        for (const auto &i : A) {
            if (n < i.first) {
                val += i.second / static_cast<double>(i.first) * n;
                break;
            } else {
                val += i.second;
                n -= i.first;
            }
        }
        printf("%.2lf\n", val);
    }
    return 0;
}