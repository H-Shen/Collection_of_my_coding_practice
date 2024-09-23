// https://ac.nowcoder.com/acm/problem/14673

#include <cstdio>
#include <cstring>

const int maxn = 10;
char s[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; ++i) {
        sprintf(s, "%d", i);
        if (i % 4 == 0 || strstr(s, "4")) {
            continue;
        }
        printf("%d\n", i);
    }
    return 0;
}