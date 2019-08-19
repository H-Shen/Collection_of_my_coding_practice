#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N, i, j;
    ll p;
    scanf("%d %lld", &N, &p);
    vector<ll> A(N);
    for (i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }
    sort(A.begin(), A.end());
    int cnt = 0;
    for (i = 0; i < N; ++i) {
        for (j = i + cnt; j < N; ++j) {
            if (j >= N || A[j] > A[i] * p) {
                break;
            }
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}