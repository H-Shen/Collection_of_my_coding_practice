#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2.0;
    printf("%.1lf\n", sqrt(p*(p-a)*(p-b)*(p-c)));
    return 0;
}