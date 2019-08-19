#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, tmp, i;
    unordered_map<int, int> A;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &tmp);
        ++A[tmp];
    }
    scanf("%d", &k);
    vector<int> query(k);
    for (i = 0; i < k; ++i) {
        scanf("%d", &query[i]);
    }
    for (i = 0; i < k - 1; ++i) {
        printf("%d ", A[query[i]]);
    }
    printf("%d\n", A[query[k - 1]]);

    return 0;
}