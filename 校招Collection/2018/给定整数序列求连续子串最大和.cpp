// https://www.nowcoder.com/practice/5a93963ecd2444a29c3e078e0a0c8796

#include <bits/stdc++.h>

using namespace std;

inline
int maxSubsequence(const vector<int> &A) {

    if (A.empty()) {
        return 0;
    }

    int n = static_cast<int>(A.size());
    int currentSum = 0, maxSum = 0, interval = A[0];

    for (int i = 0; i < n; ++i) {
        currentSum += A[i];

        if (A[i] <= 0 && A[i] > interval) {
            interval = A[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        } else if (currentSum < 0) {
            currentSum = 0;
        }
    }

    if (maxSum == 0)
        return interval;
    return maxSum;
}

int main() {

    vector<int> A;
    int n;
    while (~scanf("%d", &n)) {
        A.emplace_back(n);
    }
    printf("%d\n", maxSubsequence(A));
    return 0;
}