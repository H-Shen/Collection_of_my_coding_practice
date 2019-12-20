#include <bits/stdc++.h>
// Thanks for the original solution provided in https://www.liuchuo.net/archives/2248


using namespace std;
const int MAXN = 200005;
int A[MAXN];

int main() {

    int i, n, m, temp, count = 0;
    scanf("%d", &n);

    // Start from index == 1
    for (i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    scanf("%d", &m);

    // The index of median if we start loading input from index == 1
    int midpos = (n + m + 1) / 2;

    // Reset i
    i = 1;

    // Online processing all entries in the second array in order to saving the space cost
    for (int j = 0; j < m; j++) {
        scanf("%d", &temp);
        while (A[i] < temp && i <= n) {
            ++count;
            if (count == midpos) {
                printf("%d\n", A[i]);
                return 0;
            }
            ++i;
        }
        ++count;
        if (count == midpos) {
            printf("%d\n", temp);
            return 0;
        }
    }

    // If all entries in the second array have been processed and the median is still not found, it must be the case
    // that A[i] >= temp where temp is any entry in the second array and count != midpos, in this case,
    // the median is in the first array, so we only need to increase 'count' to the 'midpos'.
    while (i <= n) {
        ++count;
        if (count == midpos) {
            printf("%d\n", A[i]);
            return 0;
        }
        ++i;
    }
    return 0;
}
