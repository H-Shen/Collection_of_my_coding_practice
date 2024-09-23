// https://ac.nowcoder.com/acm/problem/15035

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000005
#define N 10

int arr[MAXN];
char s[N];

int main(void)
{
    int i;
    int cnt = 0;
    for (i = 0; i < MAXN; ++i) {
        sprintf(s, "%d", i);
        if (strstr(s, "38") || strstr(s, "4")) {
            ++cnt;
        }
        arr[i] = cnt;
    }

    int left, right, res;
    while (true) {
        scanf("%d %d", &left, &right);
        if (left == 0 && right == 0) {
            break;
        }
        res = arr[right] - arr[left];
        sprintf(s, "%d", left);
        if (strstr(s, "38") || strstr(s, "4")) {
            ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}