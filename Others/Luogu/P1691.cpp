#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 505;
char cstr[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    scanf("%s", cstr);
    string s(cstr);
    sort(s.begin(), s.end());
    int counter = 0;
    do {
        printf("%s\n", s.c_str());
        ++counter;
    } while (next_permutation(s.begin(), s.end()));
    printf("%d\n", counter);

    return 0;
}
