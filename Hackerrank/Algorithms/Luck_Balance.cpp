#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, i, tmpLuck, tmpRating;
    int luckBalance = 0, len_A = 0;
    scanf("%d %d", &n, &k);
    vector <int> A;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &tmpLuck, &tmpRating);
        if (tmpRating == 0) {
            luckBalance += tmpLuck;
        }
        else {
            A.push_back(tmpLuck);
            len_A++;
        }
    }
    sort(A.begin(), A.end());
    for (i = 0; i < len_A - k; i++) {
        luckBalance -= A[i];
    }
    if (k >= len_A) {
        for (i = 0; i < len_A; i++) {
            luckBalance += A[i];
        }
    }
    else {
        for (i = len_A - k; i < len_A; i++) {
            luckBalance += A[i];
        }
    }
    printf("%d\n", luckBalance);
    return 0;
}
