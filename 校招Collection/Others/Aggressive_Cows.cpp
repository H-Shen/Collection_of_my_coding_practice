// https://ac.nowcoder.com/acm/contest/951/A

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll maxn = 1000000000;
ll n, c;
vector <ll> A;

bool test(const ll & dis)
{
    ll last = 0;
    ll cnt;
    for (ll i = 1; i < c; ++i) {
        cnt = last + 1;
        while (cnt < n && A[cnt] - A[last] < dis) {
            ++cnt;
        }
        if (cnt == n) {
            return false;
        }
        last = cnt;
    }
    return true;
}

int main()
{
    scanf("%lld %lld", &n, &c);
    A.resize(static_cast<unsigned long>(n));
    for (auto &p : A) {
        scanf("%lld", &p);
    }
    sort(A.begin(), A.end());

    ll left = 0, right = maxn , mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        if (test(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%lld\n", left);

    return 0;
}