// https://ac.nowcoder.com/acm/problem/14965

#include <bits/stdc++.h>

using namespace std;

constexpr double eps = 1e-6;

inline static
int sgn(double a) {
    if (a < -eps) {
        return -1;
    }
    if (a < eps) {
        return 0;
    }
    return 1;
}

struct Gun {
    int q{}, len{};
    vector<int> a;
    double w = 0.0;
};

bool operator<(const Gun &a, const Gun &b) {
    return (sgn(a.w - b.w) < 0);
}

int main() {
    int n, m, i, j;
    while (~scanf("%d %d", &n, &m)) {
        vector<Gun> A(static_cast<unsigned long>(n));

        for (i = 0; i < n; ++i) {
            scanf("%d %d", &A[i].q, &A[i].len);
            A[i].a.resize(static_cast<unsigned long>(A[i].len));
            for (j = 0; j < A[i].len; ++j) {
                scanf("%d", &A[i].a[j]);
            }
        }

        unordered_map<int, double> B;
        for (i = 0; i < m; ++i) {
            pair<int, double> tmp;
            scanf("%d %lf", &tmp.first, &tmp.second);

            if (B.find(tmp.first) == B.end()) {
                B.insert(tmp);
            } else if (sgn(B[tmp.first] - tmp.second) < 0) {
                B[tmp.first] = tmp.second;
            }
        }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < A[i].len; ++j) {
                A[i].w = A[i].w + B[A[i].a[j]];
            }
            A[i].w = (A[i].w + 1.0) * static_cast<double>(A[i].q);
        }
        printf("%.4lf\n", (*max_element(A.begin(), A.end())).w);
    }

    return 0;
}