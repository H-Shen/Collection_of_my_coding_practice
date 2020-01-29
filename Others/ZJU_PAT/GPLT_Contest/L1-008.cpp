#include <bits/stdc++.h>

int main() {
    int a, b, i;
    int sum = 0, cycle = 0;
    scanf("%d %d", &a, &b);
    for (i = a; i <= b; ++i) {
        sum += i;
        cycle++;
        printf("%5d", i);
        if (i == b || cycle % 5 == 0) {
            printf("\n");
        }
    }

    printf("Sum = %d\n", sum);

    return 0;
}