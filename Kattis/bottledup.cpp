// https://open.kattis.com/problems/bottledup
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int a, b, v1, v2, s;
    int result_a = -1;
    int result_b = -1;
    int result_sum = numeric_limits<int>::max();
    int temp;
    int temp_sum;
    scanf("%d %d %d", &s, &v1, &v2);
    for (a = 0;; ++a) {
        temp = a * v1;
        if (temp > s) {
            break;
        }
        if ((s - temp) % v2 == 0) {
            b = (s - temp) / v2;
            temp_sum = a + b;
            if (temp_sum < result_sum) {
                result_sum = temp_sum;
                result_a = a;
                result_b = b;
            }
        }
    }
    if (result_a == -1 && result_b == -1) {
        printf("Impossible\n");
    } else {
        printf("%d %d\n", result_a, result_b);
    }

    return 0;
}
