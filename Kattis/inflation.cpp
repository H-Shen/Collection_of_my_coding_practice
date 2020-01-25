// https://open.kattis.com/problems/inflation
//
#include <bits/extc++.h>

using namespace std;
constexpr double EPS = 1e-8;

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &&i : A) {
        scanf("%d", &i);
    }
    sort(A.begin(), A.end());
    vector<double> result(n);
    for (int i = 0; i < n; ++i) {
        if (A[i] > i + 1) {
            printf("impossible\n");
            return 0;
        }
        result[i] = A[i] * 1.0 / (i + 1);
    }
    printf("%.6lf\n", *min_element(result.begin(), result.end(), [](const double &lhs, const double &rhs) {
        int tempVal = sgn(lhs - rhs);
        return (tempVal == -1);
    }));

    return 0;
}
