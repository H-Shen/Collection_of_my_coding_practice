#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N;
    scanf("%d", &N);
    vector<ll> A(N);
    int i, j;
    for (i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }
    ll sum = 0;

    for (i = 0; i < N - 1; ++i) {
        for (j = i + 1; j < N; ++j) {
            sum = sum + 10 * A[i] + A[j];
            sum = sum + 10 * A[j] + A[i];
        }
    }
    printf("%lld\n", sum);
    return 0;
}