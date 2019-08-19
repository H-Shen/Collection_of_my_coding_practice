#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    scanf("%d", &n);
    vector<int> A(static_cast<size_t>(n));
    for (i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    // exception 0
    if (n == 1) {
        printf("1\n%d\n", A.front());
        return 0;
    }

    vector<int> leftMax(static_cast<size_t>(n));
    int maxVal = numeric_limits<int>::min();
    for (i = 0; i < n; ++i) {
        maxVal = max(maxVal, A[i]);
        leftMax[i] = maxVal;
    }

    vector<int> rightMin(n);
    int minVal = numeric_limits<int>::max();
    for (i = n - 1; i >= 0; --i) {
        minVal = min(minVal, A[i]);
        rightMin[i] = minVal;
    }

    vector<int> res;
    for (i = 0; i < n; ++i) {
        if (i == 0 && A[0] < rightMin[1]) {
            res.emplace_back(A[0]);
        } else if (i == n - 1 && A[n - 1] > leftMax[n - 2]) {
            res.emplace_back(A[n - 1]);
        } else if (A[i] > leftMax[i - 1] && A[i] < rightMin[i + 1]) {
            res.emplace_back(A[i]);
        }
    }

    printf("%lu\n", res.size());
    if (res.empty()) {
        printf("\n");
        return 0;
    }

    for (size_t j = 0; j < res.size() - 1; ++j) {
        printf("%d ", res[j]);
    }
    printf("%d\n", res.back());

    return 0;
}