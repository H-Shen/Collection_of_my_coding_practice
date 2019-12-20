// https://ac.nowcoder.com/acm/problem/14716

#include <bits/stdc++.h>

using namespace std;

const int N = 13;
int a[N][N] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },{ 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 2, 2, 1 },{ 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 2, 2, 1 },{ 1, 2, 2, 3, 3, 4, 4, 4, 3, 3, 2, 2, 1 },{ 1, 2, 2, 3, 3, 4, 4, 4, 3, 3, 2, 2, 1 },{ 1, 2, 2, 3, 3, 4, 4, 4, 3, 3, 2, 2, 1 },{ 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 2, 2, 1 },{ 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 2, 2, 1 },{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };


int main()
{
    int n, i, j, sum;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        getchar();
        char A[N][N];
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                scanf("%c", &A[i][j]);
            }
            getchar();
        }
        sum = 0;
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                if (A[i][j] == '#') {
                    sum += a[i][j];
                }
            }
        }
        printf("%.2lf\n", static_cast<double>(sum) / static_cast<double>(n));
    }


    return 0;
}