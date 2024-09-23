#include <bits/stdc++.h>


using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> A(k);
    for (auto &p : A) {
        cin >> p;
    }

    int m = 1, n = k;

    while (true) {
        if (m >= n && m * n == k) {
            break;
        }
        ++m;
        n = k / m;
    }

    sort(A.begin(), A.end(), greater<>());
    vector<vector<int> > a(m);
    for (auto &p : a) {
        p.resize(n);
    }

    int i, j;
    if (m == 1) {
        for (i = 0; i < n; ++i) {
            a[0][i] = A[i];
        }
    } else if (n == 1) {
        for (i = 0; i < m; ++i) {
            a[i][0] = A[i];
        }
    } else {

        int cnt = 0;
        int leftCorneri = 0, leftCornerj = 0, rightCorneri = m - 1, rightCornerj = n - 1;
        while (true) {
            for (i = leftCorneri; i <= rightCornerj; ++i) {
                a[leftCorneri][i] = A[cnt++];
            }
            if (cnt == k) {
                break;
            }
            for (i = leftCorneri + 1; i <= rightCorneri; ++i) {
                a[i][rightCornerj] = A[cnt++];
            }
            if (cnt == k) {
                break;
            }
            for (i = rightCornerj - 1; i >= leftCornerj; --i) {
                a[rightCorneri][i] = A[cnt++];
            }
            if (cnt == k) {
                break;
            }
            for (i = rightCorneri - 1; i >= leftCorneri + 1; --i) {
                a[i][leftCornerj] = A[cnt++];
            }
            if (cnt == k) {
                break;
            }

            ++leftCorneri;
            ++leftCornerj;
            --rightCorneri;
            --rightCornerj;
        }
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n - 1; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][n - 1]);
    }
    return 0;
}