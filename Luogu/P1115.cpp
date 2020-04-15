#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

ll maxSubsequence(const vector<ll> &A) {

    ll n = static_cast<int>(A.size());
    ll currentSum = 0, maxSum = 0, interval = A.front();
    for (int i = 0; i < n; i++) {
        currentSum += A.at(i);

        if (A.at(i) <= 0 && A.at(i) > interval) {
            interval = A.at(i);
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        else if (currentSum < 0) {
            currentSum = 0;
        }
    }

    if (maxSum == 0) {
        return interval;
    }
    return maxSum;
}

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    printf("%lld\n", maxSubsequence(A));

    return 0;
}
