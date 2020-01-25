// https://open.kattis.com/problems/password
//
#include <bits/extc++.h>

using namespace std;

constexpr double EPS = 1e-8;
constexpr int MAXLEN = 20;
char s[MAXLEN];

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
    vector<double> A(n);
    for (auto &&i : A) {
        scanf("%s %lf", s, &i);
    }

    sort(A.begin(), A.end(), [](const double &lhs, const double &rhs) {
        int tempVal = sgn(lhs - rhs);
        return (tempVal == 1);
    });

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += (i + 1) * A[i];
    }
    printf("%.4lf\n", sum);

    return 0;
}
