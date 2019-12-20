// https://www.nowcoder.com/practice/38af9b5a06ea4448ae9b2a488b6a991f

#include <cstdio>

typedef long long int ll;

ll Count(ll n) {
    ll ccount = 0;
    ll Factor = 1;
    ll LowerNum = 0;
    ll CurrNum = 0;
    ll HigherNum = 0;
    if (n <= 0) {
        return 0;
    }
    while (n / Factor != 0) {
        LowerNum = n - (n / Factor) * Factor;
        CurrNum = (n / Factor) % 10;
        HigherNum = n / (Factor * 10);
        if (CurrNum == 0) {
            ccount += HigherNum * Factor;
        } else if (CurrNum == 1) {
            ccount += HigherNum * Factor + LowerNum + 1;
        } else {
            ccount += (HigherNum + 1) * Factor;
        }
        Factor *= 10;
    }
    return ccount;
}

int main() {
    ll a;
    scanf("%lld", &a);
    printf("%lld\n", Count(a));
    return 0;
}
