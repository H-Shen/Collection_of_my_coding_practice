// https://www.nowcoder.com/practice/1843c3b052984e3f98c68935ea3c0d79

#include <cstdio>

using namespace std;

const int MOD = 32767;
const int MAXN = 1000005;
int A[MAXN] = {1, 2};

int main() {

    for (int i = 2; i < MAXN; ++i) {
        A[i] = (2 * A[i - 1] + A[i - 2]) % MOD;
    }

    int n, k;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        printf("%d\n", A[k - 1]);
    }
    return 0;
}