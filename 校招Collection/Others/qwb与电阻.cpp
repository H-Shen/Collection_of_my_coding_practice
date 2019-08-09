// https://ac.nowcoder.com/acm/problem/14744

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    ll r1, r2, r3;
    while (T--) {
        cin >> r1 >> r2 >> r3;
        printf("%.2lf\n", (r1 + r3 + sqrt(static_cast<double>((r1 + r3) * (r1 + r3 + 4 * r2)))) / 2.0);
    }

    return 0;
}