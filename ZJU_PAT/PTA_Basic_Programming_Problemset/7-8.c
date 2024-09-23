#include <stdio.h>

#define MAX 60

int main() {
    int v;
    scanf("%d", &v);
    printf((v <= MAX) ? ("Speed: %d - OK\n") : ("Speed: %d - Speeding\n"), v);
    return 0;
}