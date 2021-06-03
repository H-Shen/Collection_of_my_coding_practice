// https://open.kattis.com/problems/ratingproblems

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int n, k, val;
    int sum = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &val);
        sum += val;
    }
    int maxVal = 3*(n-k) + sum;
    printf("%.4lf %.4lf\n", (-3*(n-k) + sum)*1.0/n, (3*(n-k) + sum)*1.0/n);

    return 0;
}
