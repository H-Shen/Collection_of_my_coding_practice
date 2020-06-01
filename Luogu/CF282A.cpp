#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 5;
char s[MAXN];

int main(int argc, char *argv[]) {

    int n;
    int x = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (strchr(s, '-')) {
            --x;
        } else {
            ++x;
        }
    }
    printf("%d\n", x);
    return 0;
}
