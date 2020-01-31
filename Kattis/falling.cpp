// https://open.kattis.com/problems/falling
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int d;
    scanf("%d", &d);
    int n2, n1, x, y;
    int sqrt_d = (int)sqrt(d) + 1;
    for (x = sqrt_d; x >= 1; --x) {
        if (d % x == 0) {
            y = d / x;
            if ( (x + y) % 2 == 0 && (x - y) % 2 == 0 ) {
                n2 = (x + y) / 2;
                if (y > x) {
                    swap(x, y);
                }
                n1 = (x - y) / 2;
                printf("%d %d\n", n1, n2);
                return 0;
            }
        }
    }
    printf("impossible\n");

    return 0;
}
