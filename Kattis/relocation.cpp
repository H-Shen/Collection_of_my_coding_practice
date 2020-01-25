// https://open.kattis.com/problems/relocation
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

vector<ll> A;

int main() {

    int N, Q, query, C, a, b;
    ll X;
    scanf("%d %d", &N, &Q);
    A.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &A[i]);
    }
    while (Q--) {
        scanf("%d", &query);
        if (query == 1) {
            scanf("%d %lld", &C, &X);
            A[C] = X;
        } else {
            scanf("%d %d", &a, &b);
            printf("%lld\n", abs(A[a] - A[b]));
        }
    }

    return 0;
}
