#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 1005;
int A[MAXN];

int main() {

    int n;
    int val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        ++A[val];
    }
    bool first_item = true;
    int counter = 0;
    for (const int i : A) {
        if (i > 0) {
            ++counter;
        }
    }
    printf("%d\n", counter);
    for (int i = 0; i < MAXN; ++i) {
        if (A[i] > 0) {
            if (first_item) {
                first_item = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}