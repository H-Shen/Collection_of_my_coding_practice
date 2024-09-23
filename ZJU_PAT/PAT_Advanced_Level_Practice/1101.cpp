#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, i;
    scanf("%d", &n);
    vector<ll> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%lld", &A[i]);
    }

    if (n == 1) {
        printf("1\n");
        printf("%lld\n", A[0]);
    } else {

        vector<ll> leftMax(n);
        vector<ll> rightMin(n);

        ll maxVal = A[0];
        for (i = 0; i < n; ++i) {
            if (A[i] > maxVal) {
                maxVal = A[i];
            }
            leftMax[i] = maxVal;
        }

        ll minVal = A[n - 1];
        for (i = n - 1; i >= 0; --i) {
            if (A[i] < minVal) {
                minVal = A[i];
            }
            rightMin[i] = minVal;
        }

        vector<ll> res;
        for (i = 0; i < n; ++i) {
            if (i == 0 && A[i] < rightMin[i + 1]) {
                res.push_back(A[i]);
            } else if (i == n - 1 && A[i] > leftMax[i - 1]) {
                res.push_back(A[i]);
            } else if (A[i] > leftMax[i - 1] && A[i] < rightMin[i + 1]) {
                res.push_back(A[i]);
            }
        }
        printf("%d\n", static_cast<int>(res.size()));
        if (!res.empty()) {
            for (i = 0; i < static_cast<int>(res.size()) - 1; ++i) {
                printf("%lld ", res[i]);
            }
            printf("%lld\n", res[res.size() - 1]);
        } else {
            printf("\n");
        }
    }
    return 0;
}