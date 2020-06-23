#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int t, l, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &l, &r);
        printf("%d %d\n", l, l << 1);
    }

    return 0;
}