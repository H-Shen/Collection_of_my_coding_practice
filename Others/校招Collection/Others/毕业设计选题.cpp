// https://ac.nowcoder.com/acm/problem/14603

#include <bits/stdc++.h>

using namespace std;
using pairT = pair<string, double>;

constexpr int MAXN = 50;
constexpr double eps = 1e-6;
char s[MAXN];

inline static
int sgn(double a) {
    if (a < -eps) return -1;
    if (a < eps) return 0;
    return 1;
}

inline static
bool cmp(const pairT &a, const pairT &b) {
    return (sgn(a.second - b.second) < 0);
}

int main() {
    int T, n, i, tmp0, tmp1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        getchar();
        vector<pairT> A(n);
        for (i = 0; i < n; ++i) {
            scanf("%s %d %d", s, &tmp0, &tmp1);
            A[i].first = s;
            A[i].second = static_cast<double>(tmp0) / static_cast<double>(tmp1);
        }
        printf("%s\n", (*max_element(A.begin(), A.end(), cmp)).first.c_str());
    }
    return 0;
}