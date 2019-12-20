// https://www.nowcoder.com/practice/1521dea0744c46ad8c31b0bd860625d0

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

typedef long long ll;
ll A[LEN];

int cmp(const void *a, const void *b) {
    ll *lhs = (ll *) a;
    ll *rhs = (ll *) b;
    if (*lhs > *rhs) {
        return 1;
    } else if (*lhs == *rhs) {
        return 0;
    }
    return -1;
}

int main(void) {

    ll s;
    while (~scanf("%lld %lld %lld", &A[0], &A[1], &A[2])) {
        qsort(A, LEN, sizeof(ll), cmp);
        s = A[0] * A[0] + A[1] * A[1] - A[2] * A[2];
        if (s == 0) {
            printf("直角三角形\n");
        } else if (s > 0) {
            printf("锐角三角形\n");
        } else {
            printf("钝角三角形\n");
        }
    }
    return 0;
}