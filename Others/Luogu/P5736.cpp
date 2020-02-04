#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace LinearSieve {

    const int MAXN = 100005;
    ll prime[MAXN] = {0};
    ll num_prime = 0;
    ll isNotPrime[MAXN] = {1, 1};

    // Generate the prime table from 1 to MAXN
    inline static
    void pre() {
        for (ll i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (ll j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = 1;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LinearSieve::pre();
    int n, val;
    cin >> n;
    bool firstItem = true;
    while (n--) {
        cin >> val;
        if (!LinearSieve::isNotPrime[val]) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << val;
        }
    }
    cout << endl;
    return 0;
}