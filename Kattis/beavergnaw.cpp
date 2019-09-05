// https://open.kattis.com/problems/beavergnaw
//
#include <bits/stdc++.h>

using namespace std;
const long double PI = acos(-1.0);

int main() {
    int D, V;
    while (true) {
        scanf("%d %d", &D, &V);
        if (D == 0 && V == 0) {
            break;
        }
        printf("%.9Lf\n", pow(static_cast<long double>(D*D*D*1.0-6.0*V/PI), 1/3.0));
    }
    return 0;
}
