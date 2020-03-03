#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll sum = 0;
    int x;
    int n;
    scanf("%d %d", &x, &n);
    for (int i = 0; i < n; ++i) {
        if (x != 6 && x != 7) {
            sum += 250;
        }
        ++x;
        if (x == 8) {
            x = 1;
        }
    }
    printf("%lld\n", sum);


    return 0;
}
