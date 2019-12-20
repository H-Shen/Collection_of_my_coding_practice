// https://www.nowcoder.com/practice/2de4127fda5e46858aa85d254af43941

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1030

char s[MAXN];

int cmp(const void *lhs, const void *rhs) {
    char *a = (char *) lhs;
    char *b = (char *) rhs;
    if (*a == *b) {
        return 0;
    } else if (*a > *b) {
        return 1;
    }
    return -1;
}

int main(void) {

    while (~scanf("%s", s)) {
        qsort(s, strlen(s), sizeof(char), cmp);
        printf("%s\n", s);
    }

    return 0;
}