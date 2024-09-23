// https://www.nowcoder.com/practice/65865c6644154bb4acca764b1480ecbb

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const ll MAX = 1000000005, MIN = -MAX;

int main() {

    int n;
    while (~scanf("%d", &n)) {

        ll x0 = MAX, y0 = MAX, x1 = MIN, y1 = MIN;
        ll x, y;

        while (n--) {
            scanf("%lld %lld", &x, &y);
            x0 = min(x0, x);
            y0 = min(y0, y);
            x1 = max(x1, x);
            y1 = max(y1, y);
        }
        ll side = max(abs(y1 - y0), abs(x1 - x0));
        printf("%lld\n", side * side);
    }

    return 0;
}