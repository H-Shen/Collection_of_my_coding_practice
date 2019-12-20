// https://www.nowcoder.com/practice/635ff765d4af45b5bf8e3756ed415792

#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, n, i;
    while (scanf("%d %d", &m, &n) != EOF) {

        int s1[10005], s2[10005], s3[20015];

        for (i = 0; i < m; i++)
            scanf("%d", &s1[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &s2[i]);

        for (i = 0; i < m; i++)
            s3[i] = s1[i];
        for (i = m; i < m + n; i++)
            s3[i] = s2[i - m];

        sort(s3, s3 + m + n);
        int k = unique(s3, s3 + m + n) - s3;

        for (i = 0; i < k - 1; i++) {
            printf("%d ", s3[i]);
        }
        printf("%d\n", s3[k - 1]);

    }
    return 0;
}