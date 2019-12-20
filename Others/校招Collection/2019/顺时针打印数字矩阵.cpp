// https://www.nowcoder.com/practice/ce0c22a435114108bd9acc75f81b5802

#include <bits/stdc++.h>

using namespace std;

vector<int> clockwisePrint(const vector<vector<int> > &mat, int n, int m) {

    int leftCorneri = 0, leftCornerj = 0, rightCorneri = n - 1, rightCornerj = m - 1;
    int counter = 0;
    int i;
    vector<int> result;
    int total = n * m;

    if (n == 0 || m == 0)
        return result;

    if (n == 1) {
        for (i = 0; i <= m - 1; i++) {
            result.push_back(mat[0][i]);
        }
    } else if (m == 1) {
        for (i = 0; i <= n - 1; i++) {
            result.push_back(mat[i][0]);
        }
    } else {
        while (true) {
            for (i = leftCorneri; i <= rightCornerj; i++) {
                result.push_back(mat[leftCorneri][i]);
                counter++;
            }
            if (counter == total)
                break;
            for (i = leftCornerj + 1; i <= rightCorneri; i++) {
                result.push_back(mat[i][rightCornerj]);
                counter++;
            }
            if (counter == total)
                break;
            for (i = rightCornerj - 1; i >= leftCornerj; i--) {
                result.push_back(mat[rightCorneri][i]);
                counter++;
            }
            if (counter == total)
                break;
            for (i = rightCorneri - 1; i >= leftCorneri + 1; i--) {
                result.push_back(mat[i][leftCornerj]);
                counter++;
            }
            if (counter == total)
                break;
            leftCorneri++;
            leftCornerj++;
            rightCorneri--;
            rightCornerj--;
        }
    }
    return result;
}

int main() {

    int m, n;
    while (true) {
        scanf("%d %d", &m, &n);
        if (m == -1 && n == -1) {
            break;
        }
        vector<vector<int> > A(m, vector<int>(n));
        for (auto &&i : A) {
            for (auto &&j : i) {
                scanf("%d", &j);
            }
        }
        vector<int> result = clockwisePrint(A, m, n);
        bool firstItem = true;
        for (const auto &i : result) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(",");
            }
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}