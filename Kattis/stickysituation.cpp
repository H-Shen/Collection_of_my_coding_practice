// https://open.kattis.com/problems/stickysituation
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < n - 1; ++i) {
        if (A.at(i - 1) + A.at(i) > A.at(i + 1)) {
            printf("possible\n");
            return 0;
        }
    }
    printf("impossible\n");

    return 0;
}
