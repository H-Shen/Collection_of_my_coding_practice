#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 10005;
ll A[MAXN];

ll maxSubsequence(ll A[], ll n) {

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

void maxSubsequenceCheck(ll A[], ll n, ll targetSum) {

    //n == 0
    if (n == 0) {
        cout << endl;
        return;
    }

    //all n numbers are negative
    bool allNumAreNeg = true;
    for (ll i = 0; i < n; ++i) {
        if (A[i] >= 0) {
            allNumAreNeg = false;
            break;
        }
    }

    if (allNumAreNeg) {
        cout << 0 << ' ' << A[0] << ' ' << A[n - 1] << endl;
        return;
    }

    if (targetSum <= 0) {
        for (int i = 0; i < n; i++) {
            if (A[i] == targetSum) {
                printf("%lld %lld %lld\n", targetSum, A[i], A[i]);
                return;
            }
        }
    } else {

        ll currentSum = 0, maxSum = 0, interval = A[0];
        ll startPos = 0, endPos = 0, startPosSave = 0;

        for (ll i = 0; i < n; i++) {
            currentSum += A[i];
            if (A[i] <= 0 && A[i] > interval) {
                interval = A[i];
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
                startPosSave = startPos;
                endPos = i;
                if (maxSum == targetSum) {
                    printf("%lld %lld %lld\n", targetSum, A[startPosSave], A[endPos]);
                    return;
                }
            } else if (currentSum < 0) {
                currentSum = 0;
                startPos = i + 1;
            }
        }
    }
}

int main() {

    ll items, targetSum;
    scanf("%lld", &items);
    for (ll i = 0; i < items; i++) {
        scanf("%lld", &A[i]);
    }

    targetSum = maxSubsequence(A, items);
    maxSubsequenceCheck(A, items, targetSum);

    return 0;
}
