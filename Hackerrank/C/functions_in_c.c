#include <stdio.h>
#include <stdlib.h>

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int cmp(const void *a, const void *b)
{
    int num_a = *((int *)a);
    int num_b = *((int *)b);
    if (num_a == num_b) {
        return 0;
    }
    if (num_a > num_b) {
        return -1;
    }
    return 1;
}
int max_of_four(int a, int b, int c, int d)
{
    int A[] = {a, b, c, d};
    qsort(A, sizeof(A) / sizeof(A[0]), sizeof(A[0]), cmp);
    return A[0];
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}