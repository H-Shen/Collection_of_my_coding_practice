#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 105;
constexpr int MAX_LEN = 10;
char s[MAXN];

int main() {

    int n;
    int length;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        length = strlen(s);
        if (length <= MAX_LEN) {
            printf("%s\n", s);
        } else {
            printf("%c", s[0]);
            printf("%d", length - 2);
            printf("%c\n", s[length - 1]);
        }
    }

    return 0;
}