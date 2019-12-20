#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    scanf("%d", &n);
    vector<double> A(static_cast<size_t>(n));
    for (i = 0; i < n; ++i) {
        scanf("%lf", &A[i]);
    }
    double s = 0.0;
    for (i = 0; i < n; ++i) {
        s = s + A[i] * (i + 1) * (n - i);
    }
    printf("%.2lf\n", s);
    return 0;
}