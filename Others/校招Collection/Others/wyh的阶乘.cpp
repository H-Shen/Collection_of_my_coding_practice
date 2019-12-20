// https://ac.nowcoder.com/acm/problem/15435

#include <cstdio>

using namespace std;
using ll = long long;

int main()
{
    int T;
    ll cnt, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        cnt = 0;
        while (n > 0) {
            cnt += n / 5;
            n /= 5;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}