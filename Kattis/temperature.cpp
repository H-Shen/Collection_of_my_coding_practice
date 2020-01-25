// https://open.kattis.com/problems/temperature
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int x, y;
    cin >> x >> y;
    if (y != 1) {
        if (x % (1 - y) == 0) {
            printf("%d\n", x / (1 - y));
        } else {
            printf("%.9lf\n", static_cast<double>(x) / (1 - y));
        }
    } else {
        if (x == 0) {
            printf("ALL GOOD\n");
        } else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}
