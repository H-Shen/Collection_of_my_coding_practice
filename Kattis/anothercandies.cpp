// https://open.kattis.com/problems/anothercandies
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        __int128 sum = 0;
        ll val;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &val);
            sum += val;
        }
        if (sum % n == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
