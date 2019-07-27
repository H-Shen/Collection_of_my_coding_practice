#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    // Complete the code to print the pattern.
    int len = 2 * n - 1;
    int A[len][len];

    //initialization
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            A[i][j] = 0;
        }
    }

    //the outer circle
    for (int i = 0; i < len; ++i) {
        A[0][i] = n;
    }
    for (int i = 0; i < len; ++i) {
        A[i][len - 1] = n;
    }
    for (int i = 0; i < len; ++i) {
        A[len - 1][i] = n;
    }
    for (int i = 0; i < len; ++i) {
        A[i][0] = n;
    }

    //inner circles
    for (int i = 1; i < n; ++i) {
        int j = i;
        int k = i;

        while (A[j][k] == 0) {
            A[j][k] = n - i;
            ++k;
        }
        ++j;
        --k;
        while (A[j][k] == 0) {
            A[j][k] = n - i;
            ++j;
        }
        --k;
        --j;
        while (A[j][k] == 0) {
            A[j][k] = n - i;
            --k;
        }
        --j;
        ++k;
        while (A[j][k] == 0) {
            A[j][k] = n - i;
            --j;
        }
    }

    //output
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("%d\n", A[i][len - 1]);
    }

    return 0;
}
