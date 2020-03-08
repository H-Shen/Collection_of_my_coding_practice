// https://open.kattis.com/problems/compass
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if (n1 == n2) {
        printf("0\n");
        return 0;
    }
    int n1_copy(n1);
    int n2_copy(n2);
    // Case 1: clockwise
    int step1 = 0;
    while (n1 != n2) {
        ++n1;
        if (n1 == 360) {
            n1 = 0;
        }
        ++step1;
    }
    int step2 = 0;
    n1 = n1_copy;
    n2 = n2_copy;
    // Case 2: anti-clockwise
    while (n1 != n2) {
        --n1;
        if (n1 == -1) {
            n1 = 359;
        }
        ++step2;
    }
    if (step1 == step2) {
        printf("180\n");
    } else if (step1 < step2) {
        printf("%d\n", step1);
    } else {
        printf("-%d\n", step2);
    }

    return 0;
}
