// https://open.kattis.com/problems/heliocentric
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int e, m, k;
    int kase = 1;
    while (~scanf("%d %d", &e, &m)) {
        k = 0;
        while (true) {
            if ((e + k) % 365 == 0 && (m + k) % 687 == 0) {
                break;
            }
            ++k;
        }
        printf("Case %d: %d\n", kase, k);
        ++kase;
    }

    return 0;
}
