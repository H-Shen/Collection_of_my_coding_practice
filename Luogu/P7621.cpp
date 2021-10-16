#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    int n;
    double a;
    int b;
    scanf("%d", &n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf%d",&a,&b);
        sum += a * b;
    }
    sum *= 0.85;
    printf("%.1lf\n", int(sum * 10 + 0.01) / 10.0);
    return 0;
}