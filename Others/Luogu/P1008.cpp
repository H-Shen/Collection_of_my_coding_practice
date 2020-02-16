#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    vector<int> A(9);
    iota(A.begin(), A.end(), 1);
    int a, b, c;
    do {
        a = 100 * A[0] + 10 * A[1] + A[2];
        b = 100 * A[3] + 10 * A[4] + A[5];
        c = 100 * A[6] + 10 * A[7] + A[8];
        if (b == a * 2 && c == a * 3) {
            printf("%d %d %d\n", a, b, c);
        }
    } while (next_permutation(A.begin(), A.end()));
    return 0;
}