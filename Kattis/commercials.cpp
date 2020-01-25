// https://open.kattis.com/problems/commercials
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

ll maxSubsequence(const vector<ll> &A) {

    ll n = static_cast<int>(A.size());
    ll currentSum = 0, maxSum = 0, interval = A[0];
    for (int i = 0; i < n; i++) {
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

    int n;
    ll p;
    scanf("%d %lld", &n, &p);
    vector<ll> A(n);
    for (auto &i : A) {
        scanf("%lld", &i);
        i -= p;
    }
    printf("%lld\n", maxSubsequence(A));

    return 0;
}
