// https://open.kattis.com/problems/helpaphd
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 15;
char s[MAXN];

int main() {

    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (strcmp("P=NP", s) == 0) {
            printf("skipped\n");
        } else {
            sscanf(s, "%d+%d", &a, &b);
            printf("%d\n", a + b);
        }
    }
    return 0;
}
