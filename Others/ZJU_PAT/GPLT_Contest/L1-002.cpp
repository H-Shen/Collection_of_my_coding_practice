#include <bits/stdc++.h>

using namespace std;

int Level(int n) {
    int sq = sqrt((n - 1) / 2.0);
    while (1 + 2 * (1 + sq) * sq > n) {
        --sq;
    }
    return sq;
}

int main() {

    int n, i, j;
    char ch;
    int emptyBit = 0;
    scanf("%d %c", &n, &ch);
    int level = Level(n);

    int diff = n - 1 - 2 * level * (level + 2);
    if (diff < 0) {
        --level;
        diff = n - 1 - 2 * level * (level + 2);
    }

    for (i = level; i >= 1; --i) {
        for (j = 1; j <= emptyBit; ++j) {
            printf(" ");
        }
        ++emptyBit;
        for (j = 1; j <= 2 * (i + 1) - 1; ++j) {
            printf("%c", ch);
        }
        printf("\n");
    }

    for (j = 1; j <= emptyBit; ++j) {
        printf(" ");
    }
    printf("%c\n", ch);

    for (i = 1; i <= level; ++i) {
        --emptyBit;
        for (j = 1; j <= emptyBit; ++j) {
            printf(" ");
        }
        for (j = 1; j <= 2 * (i + 1) - 1; ++j) {
            printf("%c", ch);
        }
        printf("\n");
    }

    printf("%d", diff);
    return 0;
}