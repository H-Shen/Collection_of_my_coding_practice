// https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db

#include <cstdio>

using namespace std;

const int MAXN = 100005;
int A[MAXN];

int maxSubsequence(int A[], int n) {

    int currentSum = 0, maxSum = 0, interval = A[0];
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
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        scanf("%d", &A[j]);
    }
    printf("%d\n", maxSubsequence(A, n));
    return 0;
}