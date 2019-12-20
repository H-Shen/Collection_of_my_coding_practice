// https://www.nowcoder.com/practice/97ba57c35e9f4749826dc3befaeae109

#include <bits/stdc++.h>

using namespace std;

inline
bool cmp(const int &A, const int &B) {
    return (A > B);
}

inline
bool stackOrderIsLegal(const vector<int> &a, const int &len) {

    int i, j, tmpLen;
    bool isLegal = true;

    for (i = 0; i < len - 1; ++i) {
        tmpLen = 0;
        vector<int> tmp((unsigned long) len);

        for (j = i + 1; j < len; ++j) {

            if (a[i] > a[j]) {
                tmp[tmpLen] = a[j];
                ++tmpLen;
            }
        }

        if (!is_sorted(tmp.begin(), tmp.begin() + tmpLen, cmp)) {
            isLegal = false;
            break;
        }
    }

    return isLegal;
}

int main() {

    int n, i;

    while (~scanf("%d", &n)) {

        vector<int> A(static_cast<unsigned long>(n));
        unordered_map<int, int> A2A_idx;
        vector<int> A_change(static_cast<unsigned long>(n));

        for (i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            A2A_idx[A[i]] = i + 1;
        }

        sort(A.begin(), A.end());

        do {
            for (i = 0; i < n; ++i) {
                A_change[i] = A2A_idx[A[i]];
            }

            if (!stackOrderIsLegal(A_change, n)) {
                continue;
            } else {
                for (i = 0; i < n - 1; ++i) {
                    printf("%d ", A[i]);
                }
                printf("%d\n", A[n - 1]);
            }

        } while (next_permutation(A.begin(), A.end()));
    }
    return 0;
}