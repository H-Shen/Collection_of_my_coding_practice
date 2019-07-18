#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 100005, MINVAL_INITIAL = 1000005, MAXVAL_INITIAL = -1;
int maxl[N][16];
int n;

void S_table() {
    int l = int(log((double)n)/log(2.0));
    for (int j=1;j<=l;j++)
    {
        for (int i=1; i + (1 << (j-1) ) - 1 <=n;++i)
        {
            maxl[i][j] = max(maxl[i][j-1], maxl[i + (1 << (j-1) )][j-1]);
        }
    }
}

int rmq(const int & l, const int & r) {
    int k = int(log((double)(r-l+1))/log(2.0));
    int maxVal  = max(maxl[l][k], maxl[r - (1<<k) + 1][k]);
    return maxVal;
}

int main() {

    int q, i;
    scanf("%d %d", &n, &q);
    int minVal = MINVAL_INITIAL, maxVal = MAXVAL_INITIAL;

    for (i = 0; i < n; ++i) {
        scanf("%d", &maxl[i + 1][0]);
        minVal = min(minVal, maxl[i + 1][0]);
        maxVal = max(maxVal, maxl[i + 1][0]);
    }

    S_table();
    int d, minRmqVal;
    while (q--) {
        scanf("%d", &d);
        if (d == 1) {
            printf("%d\n", minVal);
        }
        else if (d == n) {
            printf("%d\n", maxVal);
        }
        else {
            minRmqVal = MINVAL_INITIAL;
            for (i = 0; i <= n - d; i++) {
                minRmqVal = min(minRmqVal, rmq(i + 1, i + d));
            }
            printf("%d\n", minRmqVal);
        }
    }
    return 0;
}
