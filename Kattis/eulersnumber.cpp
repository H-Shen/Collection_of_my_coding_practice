// https://open.kattis.com/problems/eulersnumber
#include <bits/extc++.h>

using namespace std;
const int maxn = 10005;
long double a[maxn] = {1.0};

int main() {

    for (int i = 1; i <= 10000; ++i) {
        a[i] = a[i - 1] * 1.0 / i;
    }
    int n;
    cin >> n;
    long double s = 0.0;
    for (int i = 0; i <= n; ++i) {
        s += a[i];
    }
    printf("%.12Lf\n", s);

    return 0;
}
