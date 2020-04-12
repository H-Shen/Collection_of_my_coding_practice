#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

unordered_map<int, int> A;

int main() {

    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        A[a] = i;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (A.find(a) == A.end()) {
            printf("0\n");
        } else {
            printf("%d\n", A[a]);
        }
    }

    return 0;
}