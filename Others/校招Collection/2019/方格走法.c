// https://www.nowcoder.com/practice/79b289947d854a759525dd937aa14762

#include <stdio.h>

#define MAXN 20

typedef long long ll;

ll A[MAXN] = {1};

int main(void) {

    for (ll i = 2; i <= MAXN; ++i) {
        A[i - 1] = i * A[i - 2];
    }
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", A[a + b - 1] / (A[a - 1] * A[b - 1]));

    return 0;
}