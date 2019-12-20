// https://www.nowcoder.com/practice/b90f1f5957ae4ee09b9dddf464718587

#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
    int i, j;
    vector<vector<int> > matrix(n);
    if (n == 0)
        return matrix;
    for (i = 0; i < n; i++) {
        matrix[i].resize(n);
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    int leftCorneri = 0, leftCornerj = 0, rightCorneri = n - 1, rightCornerj = n - 1;
    int counter = 0;
    int total = n * n;
    if (n == 1)
        matrix[0][0] = 1;
    else {
        while (true) {
            for (i = leftCorneri; i <= rightCornerj; i++) {
                matrix[leftCorneri][i] = counter + 1;
                counter++;
            }
            if (counter == total)
                break;
            for (i = leftCornerj + 1; i <= rightCorneri; i++) {
                matrix[i][rightCornerj] = counter + 1;
                counter++;
            }
            if (counter == total)
                break;
            for (i = rightCornerj - 1; i >= leftCornerj; i--) {
                matrix[rightCorneri][i] = counter + 1;
                counter++;
            }
            if (counter == total)
                break;
            for (i = rightCorneri - 1; i >= leftCorneri + 1; i--) {
                matrix[i][leftCornerj] = counter + 1;
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
    return matrix;
}

const int MAXN = 23;
vector<vector<vector<int> > > A(MAXN);

int main() {
    int i, j;
    for (i = 0; i <= 20; i++) {
        A[i] = generateMatrix(i);
    }
    int n, a, b;
    while (scanf("%d", &n) != EOF) {
        a = static_cast<int>(A[n].size());
        b = static_cast<int>(A[n][0].size());
        for (i = 0; i < a; i++) {
            for (j = 0; j < b - 1; j++) {
                printf("%d ", A[n][i][j]);
            }
            printf("%d\n", A[n][i][b - 1]);
        }
        printf("\n");
    }
    return 0;
}