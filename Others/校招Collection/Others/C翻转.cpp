// https://www.nowcoder.com/practice/74bdb725421c4f80b4aca7266818baf0

#include <cstdio>

const int N = 5, n = 3, m = 2;

int main() {

    int A[N][N], rot[n][n];
    int i, j, input, posX, posY, op1, op2;
    while (true) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                input = scanf("%d", &A[i][j]);
                if (input == EOF) {
                    goto ending;
                }
            }
        }
        scanf("%d %d %d %d", &op1, &op2, &posX, &posY);

        int Xor = op1 ^op2;
        --posX;
        --posY;

        switch (Xor) {
            //(1 ^ 2)
            case (3) : {
                for (i = 0; i < m; i++) {
                    for (j = 0; j < m; j++) {
                        rot[j][m - 1 - i] = A[posX + i][posY + j];
                    }
                }
                for (i = 0; i < m; i++) {
                    for (j = 0; j < m; j++) {
                        A[posX + i][posY + j] = rot[i][j];
                    }
                }
                break;
            }
                //(1 ^ 3)
            case (2) : {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        rot[j][n - 1 - i] = A[posX + i][posY + j];
                    }
                }
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        A[posX + i][posY + j] = rot[i][j];
                    }
                }
                break;
            }
                //(2 ^ 2)
            case (0) : {
                for (i = 0; i < m; i++) {
                    for (j = 0; j < m; j++) {
                        rot[m - 1 - j][i] = A[posX + i][posY + j];
                    }
                }
                for (i = 0; i < m; i++) {
                    for (j = 0; j < m; j++) {
                        A[posX + i][posY + j] = rot[i][j];
                    }
                }
                break;
            }
                //(2 ^ 3)
            default : {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        rot[n - 1 - j][i] = A[posX + i][posY + j];
                    }
                }
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        A[posX + i][posY + j] = rot[i][j];
                    }
                }
            }
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < N - 1; j++) {
                printf("%d ", A[i][j]);
            }
            printf("%d\n", A[i][N - 1]);
        }
    }
    ending:
    {
        return 0;
    }
}
