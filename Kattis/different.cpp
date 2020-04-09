// https://open.kattis.com/problems/different
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ll a, b;
    while (~scanf("%lld %lld", &a, &b)) {
        printf("%lld\n", abs(a - b));
    }
    
    return 0;
}
