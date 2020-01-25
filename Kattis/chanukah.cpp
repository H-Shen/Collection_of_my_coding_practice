// https://open.kattis.com/problems/chanukah
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int n, kase;
    ll total;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %lld", &kase, &total);
        printf("%d %lld\n", kase, total * (3 + total) / 2);
    }

    return 0;
}
