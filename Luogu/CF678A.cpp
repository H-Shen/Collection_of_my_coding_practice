#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n, k;
    cin >> n >> k;
    ll a = n / k;
    while (a * k <= n) {
        ++a;
    }
    cout << a * k << endl;


    return 0;
}