#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 105;
char s[MAXN];

int main() {

    int n, stone, i;
    bool rightAnswer;
    scanf("%d %s", &n, s);
    for (i = 0;; ++i) {
        stone = i;
        rightAnswer = true;
        // run the executions
        for (int j = 0; j < n; ++j) {
            if (s[j] == '-') {
                --stone;
                if (stone < 0) {
                    rightAnswer = false;
                    break;
                }
            } else {
                ++stone;
            }
        }
        if (rightAnswer) {
            break;
        }
    }
    stone = i;
    for (int j = 0; j < n; ++j) {
        if (s[j] == '-') {
            --stone;
        } else {
            ++stone;
        }
    }
    printf("%d\n", stone);

    return 0;
}