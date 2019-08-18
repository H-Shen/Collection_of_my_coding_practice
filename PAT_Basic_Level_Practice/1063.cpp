#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, a, b, pow;
    int pow_max = numeric_limits<int>::min();
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        pow = a * a + b * b;
        if (pow > pow_max) {
            pow_max = pow;
        }
    }
    printf("%.2lf\n", sqrt(static_cast<double>(pow_max)));
    return 0;
}