// https://ac.nowcoder.com/acm/problem/14733

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll maxn = 1000000005;

inline static
int cnt(const vector <ll> &A, ll val)
{
    if (binary_search(A.begin(), A.end(), val)) {
        return distance(A.begin(), lower_bound(A.begin(), A.end(), val)) + 1;
    }
    return distance(A.begin(), lower_bound(A.begin(), A.end(), val));
}

int main()
{
    vector <ll> A;
    for (ll i = 0; i * i < maxn; ++i) {
        A.push_back(i * i);
    }
    int query;
    ll left, right;
    int low, up, res;
    scanf("%d", &query);
    while (query--) {
        scanf("%lld %lld", &left, &right);
        res = cnt(A, right) - cnt(A, left);
        if (binary_search(A.begin(), A.end(), left)) {
            ++res;
        }
        printf("%d\n", res);
    }



    return 0;
}