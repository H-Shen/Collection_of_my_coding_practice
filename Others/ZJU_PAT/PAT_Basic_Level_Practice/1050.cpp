#include <bits/stdc++.h>

using namespace std;
const int MIN_VAL = 10000005;

bool cmp(const int &a, const int &b) {
    return (a > b);
}

int main() {

    int N;
    scanf("%d", &N);
    vector<int> A(static_cast<size_t>(N));

    int i, j;
    for (i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    sort(A.begin(), A.end(), cmp);
    int m = -1;
    int n = -1;

    int minGap = MIN_VAL;
    for (i = 1; i <= N; ++i) {
        if (N % i == 0) {
            int tmp_n = N / i;
            if (i >= tmp_n && minGap > (i - tmp_n)) {
                minGap = i - tmp_n;
                m = i;
                n = tmp_n;
            }
        }
    }

    if (m == -1 || n == -1) {
        throw invalid_argument("Invalid input!");
    }

    vector<vector<int> > a(static_cast<size_t>(m));
    for (auto &p : a) {
        p.resize(static_cast<size_t>(n));
    }
    if (m == 1) {
        for (i = 0; i < n; ++i) {
            a[0][i] = A[i];
        }
    } else if (n == 1) {
        for (i = 0; i < m; ++i) {
            a[i][0] = A[i];
        }
    } else {

        int count = 0;
        int leftCorneri = 0, leftCornerj = 0, rightCorneri = m - 1, rightCornerj = n - 1;

        while (true) {

            for (i = leftCorneri; i <= rightCornerj; ++i) {
                a[leftCorneri][i] = A[count++];
            }
            if (count == N) break;

            for (i = leftCorneri + 1; i <= rightCorneri; ++i) {
                a[i][rightCornerj] = A[count++];
            }
            if (count == N) break;

            for (i = rightCornerj - 1; i >= leftCornerj; --i) {
                a[rightCorneri][i] = A[count++];
            }
            if (count == N) break;

            for (i = rightCorneri - 1; i >= leftCorneri + 1; --i) {
                a[i][leftCornerj] = A[count++];
            }
            if (count == N) break;

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
