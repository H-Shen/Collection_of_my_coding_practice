#include <stdio.h>

void Print_Factorial(const int N);

int main() {
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* Your code will be pasted here */
#include <string.h>

#define MAXN 4005

void Print_Factorial(const int N) {

    int a[MAXN];
    char ans[MAXN];
    if (N < 0) {
        puts("Invalid input");
        return;
    } else if (N == 0) {
        puts("1");
        return;
    }

    int i, j;
    for (i = 0; i < MAXN; ++i) {
        a[i] = 0;
    }
    ans[0] = '\0';

    int s = 0, m = N;
    while (m)
        a[++s] = m % 10, m /= 10;
    for (int i = N - 1; i >= 2; i--) {
        int w = 0;
        for (int j = 1; j <= s; j++) {
            a[j] = a[j] * i + w;
            w = a[j] / 10;
            a[j] = a[j] % 10;
        }
        while (w) {
            a[++s] = w % 10;
            w /= 10;
        }
    }
    while (!a[s])
        s--;
    char tmpStr[2];
    int len = 0;
    while (s >= 1) {
        tmpStr[0] = a[s--] + ('0' - 0);
        tmpStr[1] = '\0';

        strcat(ans, tmpStr);
        len++;
    }

    printf("%s\n", ans);
}