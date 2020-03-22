// https://open.kattis.com/problems/aprizenoonecanwin
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n, x;
    scanf("%lld %lld", &n, &x);
    vector<ll> A(n);
    for (auto &i : A) scanf("%lld", &i);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    sort(A.begin(), A.end(), greater<>());
    for (int i = 0; i < n - 1; ++i) {
        if (A.at(i) + A.at(i + 1) <= x) {
            printf("%lld\n", n - i);
            return 0;
        }
    }
    printf("1\n");
    return 0;
}
