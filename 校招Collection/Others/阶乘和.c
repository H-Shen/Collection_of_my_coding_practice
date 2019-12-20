// https://ac.nowcoder.com/acm/problem/15375

#include <stdio.h>

typedef long long ll;

int main() {

    ll n;
    scanf("%lld", &n);
    ll sum = 0;
    ll temp = 1;
    for (ll i = 1; i <= n; ++i, temp = temp * i) {
        sum += temp;
    }
    printf("%lld\n", sum);

    return 0;
}
