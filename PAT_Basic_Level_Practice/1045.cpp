#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
    int n, i;
    scanf("%d", &n);
    vector<int> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    //exception0
    if (n == 1) {
        printf("1\n%d\n", A[0]);
        return 0;
    }

    vector<int> leftMax(static_cast<size_t>(n));
    int maxVal = INT_MIN;
    for (i = 0; i < n; ++i) {
        maxVal = max(maxVal, A[i]);
        leftMax[i] = maxVal;
    }

    vector<int> rightMin(n);
    int minVal = INT_MAX;
    for (i = n - 1; i >= 0; --i) {
        minVal = min(minVal, A[i]);
        rightMin[i] = minVal;
    }

    vector<int> res;
    for (i = 0; i < n; ++i) {
        if (i == 0 && A[0] < rightMin[1]) {
            res.push_back(A[0]);
        } else if (i == n - 1 && A[n - 1] > leftMax[n - 2]) {
            res.push_back(A[n - 1]);
        } else if (A[i] > leftMax[i - 1] && A[i] < rightMin[i + 1]) {
            res.push_back(A[i]);
        }
    }

    printf("%d\n", (int) res.size());
    if (res.empty()) {
        printf("\n");
        return 0;
    }

    for (vector<int>::size_type j = 0; j < res.size() - 1; ++j) {
        printf("%d ", res[j]);
    }
    printf("%d\n", res[res.size() - 1]);

    return 0;
}