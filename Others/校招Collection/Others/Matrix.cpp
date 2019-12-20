// https://ac.nowcoder.com/acm/problem/13883

#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;
int a[maxn][maxn];

int main()
{
    int T, n, q, op, k, v, i, j;
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        scanf("%d %d", &n, &q);
        while (q--) {
            scanf("%d %d %d", &op, &k, &v);
            switch (op) {
                case 1:
                    for (i = 0; i < n; ++i) {
                        a[k - 1][i] = v;
                    }
                    break;
                case 2:
                    for (i = 0; i < n; ++i) {
                        a[i][k - 1] = v;
                    }
                    break;
            }
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n - 1; ++j) {
                printf("%d ", a[i][j]);
            }
            printf("%d\n", a[i][n - 1]);
        }
    }
    return 0;
}