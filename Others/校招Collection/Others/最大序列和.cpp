// https://www.nowcoder.com/practice/df219d60a7af4171a981ef56bd597f7b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll maxSubsequence(vector<ll> A, ll n) {

    ll currentSum = 0, maxSum = 0, interval = A[0];
    for (ll i = 0; i < n; i++) {
        currentSum += A[i];

        if (A[i] <= 0 && A[i] > interval) {
            interval = A[i];
        }

        if (currentSum > maxSum)
            maxSum = currentSum;
        else if (currentSum < 0)
            currentSum = 0;
    }

    if (maxSum == 0)
        return interval;
    return maxSum;
}

int main() {

    ll n;
    while (scanf("%lld", &n) != EOF) {
        vector<ll> A(n);
        for (ll i = 0; i < n; i++) {
            scanf("%lld", &A[i]);
        }
        printf("%lld\n", maxSubsequence(A, n));
    }
    return 0;
}