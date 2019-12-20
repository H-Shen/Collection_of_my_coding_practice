#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main() {
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* Your code will be pasted here */
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    const ElementType *a_val = (const ElementType *) a;
    const ElementType *b_val = (const ElementType *) b;
    if (*a_val > *b_val) {
        return 1;
    } else if (*a_val < *b_val) {
        return -1;
    }
    return 0;
}

ElementType Median(ElementType A[], int N) {
    ElementType res = 0.0;
    if (N == 0) {
        return res;
    }
    qsort(A, N, sizeof(ElementType), cmp);
    if (N % 2 != 0) {
        return A[(N - 1) / 2];
    }
    return A[N / 2];
}