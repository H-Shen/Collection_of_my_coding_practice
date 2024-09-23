// https://www.nowcoder.com/practice/a275ca24f57242a8b9e1a225182eca01

#include <cstdio>

using namespace std;
using ll = long long;

ll Count(ll n) {
    ll count = 0;
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
            count += HigherNum * Factor;
        } else if (CurrNum == 1) {
            count += HigherNum * Factor + LowerNum + 1;
        } else {
            count += (HigherNum + 1) * Factor;
        }
        Factor *= 10;
    }
    return count;
}

int main() {
    ll n;
    while (~scanf("%lld", &n)) {
        printf("%lld\n", Count(n));
    }
    return 0;
}
