#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// a(2m+1) = a(2m), a(2m) = a(2m-1) + a(m)
unordered_map<ll, ll> A;

ll a(ll n) {
    if (A.find(n) != A.end()) {
        return A[n];
    }
    ll m = n / 2;
    ll temp;
    if (n % 2 != 0) {
        temp = a(n - 1);
    } else {
        temp = a(n - 1) + a(m);
    }
    A[n] = temp;
    return temp;
}

int main() {

    A[0] = 1;
    A[1] = 1;
    ll n;
    cin >> n;
    cout << a(n) << '\n';
    
    return 0;
}

