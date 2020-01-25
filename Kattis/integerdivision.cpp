// https://open.kattis.com/problems/integerdivision
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
unordered_map<int, ll> A;

int main() {

    int n;
    int d;
    int val;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        ++A[val / d];
    }
    ll sum = 0;
    for (const auto [k, v] : A) {
        sum += v * (v - 1) / 2;
    }
    printf("%lld\n", sum);

    return 0;
}
