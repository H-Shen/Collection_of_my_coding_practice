// https://ac.nowcoder.com/acm/problem/14416

#include <unordered_set>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    ll n, x, i;
    scanf("%lld %lld", &n, &x);
    vector <ll> A(n);

    for (i = 0; i < n; ++i) {
        scanf("%lld", &A[i]);
    }
    unordered_set <ll> A_set(A.begin(), A.end());
    int len = A_set.size();
    A.resize(len);
    copy(A_set.begin(), A_set.end(), A.begin());
    ll a, b, c;
    for (a = 0; a < len; ++a) {
        for (b = 0; b < len; ++b) {
            c = - A[a] * A[a] * x - A[b] * x;
            if (A_set.find(c) != A_set.end()) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}