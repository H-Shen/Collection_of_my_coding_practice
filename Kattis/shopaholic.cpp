// https://open.kattis.com/problems/shopaholic
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    sort(A.begin(), A.end(), greater<>());
    int counter = 0;
    ll discount = 0;
    for (int i = 0; i < n; ++i) {
        ++counter;
        if (counter == 3) {
            discount += A.at(i);
            counter = 0;
        }
    }
    printf("%lld\n", discount);
    return 0;
}
