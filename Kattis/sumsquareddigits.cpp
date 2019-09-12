// https://open.kattis.com/problems/sumsquareddigits
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> getDigits(ll n, ll b) {
    vector<ll> result;
    while (n > 0) {
        result.emplace_back(n % b);
        n /= b;
    }
    return result;
}

int main() {

    int k;
    int kase;
    ll b, n, sum;
    vector<ll> p;

    scanf("%d", &k);
    while (k--) {
        scanf("%d %lld %lld", &kase, &b, &n);
        p = getDigits(n, b);
        sum = 0;
        for (const auto &i : p) {
            sum += i * i;
        }
        printf("%d %lld\n", kase, sum);
    }

    return 0;
}
