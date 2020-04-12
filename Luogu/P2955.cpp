#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_set<char> even = {'0','2','4','6','8'};
constexpr int MAXN = 100;
char s[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        printf(even.find(s[strlen(s) - 1]) != even.end() ? "even\n" : "odd\n");
    }

    return 0;
}