#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 3005;
bitset<MAXN> A;

int main() {

    int n, val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        A[val] = true;
    }
    for (int i = 1;; ++i) {
        if (!A[i]) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}