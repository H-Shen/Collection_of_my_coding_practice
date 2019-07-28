// https://open.kattis.com/problems/twostones

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n & 1) {
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
    return 0;
}
