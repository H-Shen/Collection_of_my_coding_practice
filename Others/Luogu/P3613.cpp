#include <bits/stdc++.h>

using namespace std;
unordered_map<int, unordered_map<int, int> > A;

int main() {

    int op, n, q, i, j, k;
    scanf("%d %d", &n, &q);
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d", &i, &j, &k);
            if (k != 0) {
                A[i][j] = k;
            } else {
                A[i].erase(j);
            }
        } else {
            scanf("%d %d", &i, &j);
            printf("%d\n", A[i][j]);
        }
    }

    return 0;
}