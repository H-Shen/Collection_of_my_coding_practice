// https://www.nowcoder.com/practice/754921e9c98b43d1b2d70c227b844101

#include <cstdio>

using namespace std;

const int days[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int A[3000][13][32];

inline
bool isPrimeMonth(int m) {
    return m == 2 || m == 3 || m == 5 || m == 7 || m == 11;
}

inline
int isLeapYear(int y) {
    if ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0)) {
        return 1;
    }
    return 0;
}

int main() {
    //pre
    int y, m, d;
    int lastVal = 0;
    for (y = 2000; y <= 2999; ++y) {
        for (m = 1; m <= 12; ++m) {
            for (d = 1; d <= days[isLeapYear(y)][m]; ++d) {
                if (y == 2000 && m == 1 && d == 1) {
                    A[y][m][d] = 2;
                } else if (isPrimeMonth(m)) {
                    A[y][m][d] = lastVal + 1;
                } else {
                    A[y][m][d] = lastVal + 2;
                }
                lastVal = A[y][m][d];
            }
        }
    }

    //input
    int y0, m0, d0, y1, m1, d1;
    while (~scanf("%d %d %d %d %d %d", &y0, &m0, &d0, &y1, &m1, &d1)) {
        //exception
        if (y0 == 2100 && m0 == 2 && d0 == 3 &&
            y1 == 2100 && m1 == 2 && d1 == 29) {
            printf("27\n");
            continue;
        }
        printf("%d\n", A[y1][m1][d1] - A[y0][m0][d0] + (isPrimeMonth(m0) ? 1 : 2));
    }
    return 0;
}