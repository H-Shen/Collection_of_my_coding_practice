// https://www.nowcoder.com/practice/03d341fb6c9d42debcdd38d82a0a545c

#include <bits/stdc++.h>

using namespace std;

int maxSubsequence(int A[], int n) {

    int currentSum = 0, maxSum = 0, interval = A[0];

    for (int i = 0; i < n; i++) {
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

    int n;
    scanf("%d", &n);
    int *A = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    printf("%d\n", maxSubsequence(A, n));

    delete[] A;
    A = nullptr;

    return 0;
}