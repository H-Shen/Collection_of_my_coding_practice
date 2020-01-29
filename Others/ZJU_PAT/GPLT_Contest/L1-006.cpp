#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> Count(ll k, ll num) {
    vector<ll> result;
    while (num % k == 0) {
        result.push_back(k);
        num /= k;
        ++k;
    }
    return result;
}

int main() {

    ll n, i;
    cin >> n;
    vector<vector<ll> > k;
    for (i = 2; i < (ll) sqrt((double) n) + 1; ++i) {
        if (n % i == 0) {
            k.push_back(Count(i, n));
        }
    }
    if (k.empty()) {
        cout << 1 << endl;
        cout << n << endl;
    } else {
        ll maxLength = -1;
        for (auto &ptr : k) {
            maxLength = max(maxLength, (ll) ptr.size());
        }
        cout << maxLength << endl;
        for (auto &ptr : k) {
            if (maxLength == (ll) ptr.size()) {
                for (i = 0; i < maxLength - 1; ++i) {
                    cout << ptr[i] << '*';
                }
                cout << ptr[maxLength - 1] << endl;
                return 0;
            }
        }
    }
    return 0;
}
