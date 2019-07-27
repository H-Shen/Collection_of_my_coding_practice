#include <stdio.h>

void update(int *a, int *b) {
    // Complete this function
    int new_a = (*a) + (*b);
    int new_b = (*a) - (*b);
    if ((*a) < (*b)) {
        new_b = -new_b;
    }
    *a = new_a;
    *b = new_b;
    return;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}