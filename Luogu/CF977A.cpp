#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n;
    int k;
    cin >> n >> k;
    while (k--) {
        if (n % 10 != 0) {
            --n;
        } else {
            n /= 10;
        }
    }
    cout << n << '\n';

    return 0;
}