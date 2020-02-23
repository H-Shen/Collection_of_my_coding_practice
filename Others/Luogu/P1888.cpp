#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    vector<ll> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    ll temp = __gcd(A[0], A[2]);
    A[0] /= temp;
    A[2] /= temp;
    printf("%lld/%lld\n", A[0], A[2]);
    return 0;
}
