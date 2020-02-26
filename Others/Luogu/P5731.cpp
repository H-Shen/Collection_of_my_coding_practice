#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int> > & mat, int n, int m) {

    int leftCorneri = 0, leftCornerj = 0, rightCorneri = n - 1, rightCornerj = m - 1;
    int counter = 0;
    int i;
    vector<int> result;
    int total = n * m;
    int current_element = 1;

    if (n == 1) {
        for (i = 0; i <= m - 1; i++) {
            mat[0][i] = current_element;
            ++current_element;
        }
    }
    else if (m == 1) {
        for (i = 0; i <= n - 1; i++) {
            mat[i][0] = current_element;
            ++current_element;
        }
    }
    else {
        while (true) {
            for (i = leftCorneri; i <= rightCornerj; i++) {
                mat[leftCorneri][i] = current_element;
                ++current_element;
                counter++;
            }
            if (counter == total)
                break;
            for (i = leftCornerj + 1; i <= rightCorneri; i++) {
                mat[i][rightCornerj] = current_element;
                ++current_element;
                counter++;
            }
            if (counter == total)
                break;
            for (i = rightCornerj - 1; i >= leftCornerj; i--) {
                mat[rightCorneri][i] = current_element;
                ++current_element;
                counter++;
            }
            if (counter == total)
                break;
            for (i = rightCorneri - 1; i >= leftCorneri + 1; i--) {
                mat[i][leftCornerj] = current_element;
                ++current_element;
                counter++;
            }
            if (counter == total)
                break;
            leftCorneri++; leftCornerj++; rightCorneri--; rightCornerj--;
        }
    }
}

int main() {

    int n;
    cin >> n;
    vector<vector<int> > A(n, vector<int>(n, -1));
    solve(A, n, n);
    if (n == 4) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    printf("%2d", A.at(i).at(j));
                } else {
                    printf("%3d", A.at(i).at(j));
                }
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%3d", A.at(i).at(j));
            }
            printf("\n");
        }
    }
    return 0;
}