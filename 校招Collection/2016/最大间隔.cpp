// https://www.nowcoder.com/practice/3a571cdc72264d76820396770a151f90

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    while (~scanf("%d", &n)) {

        if (n <= 2) {
            printf("0\n");
            continue;
        }

        vector<int> A(n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        if (n == 3) {
            printf("%d\n", min(A[1] - A[0], A[2] - A[1]));
            continue;
        }

        vector<int> D(n - 1);
        for (i = 0; i < n - 2; ++i) {
            D[i] = A[i + 1] - A[i];
        }
        vector<int> minValList;
        int maxDList = *max_element(D.begin(), D.end());

        for (i = 0; i < n - 3; ++i) {
            minValList.push_back(max(D[i] + D[i + 1], maxDList));
        }
        printf("%d\n", *min_element(minValList.begin(), minValList.end()));
    }
    return 0;
}