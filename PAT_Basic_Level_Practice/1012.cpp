#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{

    bool hasA1 = false;
    bool hasA2 = false;
    bool hasA3 = false;
    bool hasA4 = false;
    bool hasA5 = false;
    int A1 = 0;
    int A2 = 0;
    int A3 = 0, cnt = 0;
    int A4 = 0;
    int A5 = INT_MIN;

    int n, tmp;
    scanf("%d", &n);
    bool change = false;

    while (n--) {
        scanf("%d", &tmp);

        if (tmp % 10 == 0) {
            A1 += tmp;
            hasA1 = true;
        }

        if (tmp % 5 == 1) {
            if (change == false) {
                A2 = A2 + tmp;
                change = true;
            }
            else {
                A2 = A2 - tmp;
                change = false;
            }
            hasA2 = true;
        }

        if (tmp % 5 == 2) {
            ++A3;
            hasA3 = true;
        }

        if (tmp % 5 == 3) {
            A4 += tmp;
            ++cnt;
            hasA4 = true;
        }

        if (tmp % 5 == 4) {
            A5 = max(A5, tmp);
            hasA5 = true;
        }
    }

    printf( (hasA1 == false) ? "N " : "%d ", A1);
    printf( (hasA2 == false) ? "N " : "%d ", A2);
    printf( (hasA3 == false) ? "N " : "%d ", A3);
    printf( (hasA4 == false) ? "N " : "%.1f ", (double)A4 / cnt);
    printf( (hasA5 == false) ? "N\n" : "%d\n", A5);

    return 0;
}
