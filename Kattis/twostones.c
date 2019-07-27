// https://open.kattis.com/problems/twostones

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("Bob\n");
    } else {
        printf("Alice\n");
    }
    return 0;
}
