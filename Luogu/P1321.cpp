#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 260;
char s[MAXN];

int main() {

    scanf("%s", s);
    string str(s);
    int boys = 0;
    int girls = 0;
    int n = static_cast<int>(str.size());
    for (int i = 2; i < n; ++i) {
        if (str[i - 2] == '.' || str[i - 1] == '.' || str[i] == '.') {
            continue;
        }
        if (str[i - 2] == 'b' || str[i - 1] == 'o' || str[i] == 'y') {
            ++boys;
        }
    }
    if (n > 3) {
        for (int i = 3; i < n; ++i) {
            if (str[i - 3] == '.' || str[i - 2] == '.' || str[i - 1] == '.' ||
                str[i] == '.') {
                continue;
            }
            if (str[i - 3] == 'g' || str[i - 2] == 'i' || str[i - 1] == 'r' ||
                str[i] == 'l') {
                ++girls;
            }
        }
    }

    printf("%d\n%d\n", boys, girls);

    return 0;
}