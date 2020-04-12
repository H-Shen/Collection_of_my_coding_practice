#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

ll solve(const vector<ll> &A, ll val) {
    if (A.empty()) {
        return val;
    }
    if (val < A.front()) {
        return abs(val - A.front());
    }
    if (val > A.back()) {
        return abs(val - A.back());
    }
    auto iter = lower_bound(A.begin(), A.end(), val);
    ll dist0 = abs(*iter - val);
    --iter;
    ll dist1 = abs(*iter - val);
    return min(dist0, dist1);
}

int main() {

    ll m, n, val;
    ll sum = 0;
    scanf("%lld %lld", &m, &n);
    vector<ll> A(m);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    sort(A.begin(), A.end());
    while (n--) {
        scanf("%lld", &val);
        sum += solve(A, val);
    }
    printf("%lld\n", sum);
    return 0;
}
