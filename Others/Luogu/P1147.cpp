#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll N;
    scanf("%lld", &N);
    N *= 2;
    ll m, n, a, b;
    vector<pair<ll, ll> > output;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            m = N / i;
            n = i;
            if ( (m + n - 1) % 2 == 0) {
                b = (m + n - 1) / 2;
                a = m - b;
                if (a >= 0 && b >= 0 && b > a) {
                    if (a > b) {
                        swap(a, b);
                    }
                    output.emplace_back(make_pair(a, b));
                }
            }
        }
    }
    sort(output.begin(), output.end(), [](const pair<ll, ll> &l, const pair<ll, ll> &r){
        return (l.first < r.first);
    });
    for (const auto &[k, v] : output) {
        printf("%lld %lld\n", k, v);
    }

    return 0;
}
