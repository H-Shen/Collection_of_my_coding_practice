#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, A_copy, n, diff, i, j;
    char ch;
    scanf("%d %c", &A, &ch);
    A_copy = A;

    while (true) {
        if (A_copy % 2 == 0) {
            --A_copy;
            continue;
        }
        n = sqrt((A_copy + 1) / 2);
        if (n * n != (A_copy + 1) / 2) {
            --A_copy;
            continue;
        }
        break;
    }
    diff = A - A_copy;
    for (i = n; i >= 1; --i) {

        for (j = 0; j <= n - i - 1; ++j) {
            putchar(' ');
        }

        for (j = 2 * i - 1; j >= 1; --j) {
            printf("%c", ch);
        }
        putchar('\n');
    }

    for (i = 2; i <= n; ++i) {

        for (j = n - i - 1; j >= 0; --j) {
            putchar(' ');
        }

        for (j = 1; j <= 2 * i - 1; ++j) {
            printf("%c", ch);
        }
        putchar('\n');
    }
    printf("%d\n", diff);
    return 0;
}