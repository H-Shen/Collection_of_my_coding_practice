// https://open.kattis.com/problems/knightstrip
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 5;
char str[MAXN];

int main() {

    ll x, y, steps, extra_steps;
    while (true) {
        scanf("%s", str);
        if (strcmp(str, "END") == 0) {
            break;
        }
        x = stoll(string(str));
        scanf("%lld", &y);
        // Since (x,y) to (0,0) is symmetric, we make sure x>0, y>0, y>x
        x = abs(x);
        y = abs(y);
        if (x > y) {
            swap(x, y);
        }
        if (y <= 2 * x) {
            if (x == 2 && y == 2) {
                steps = 4;
            } else {
                steps = (x + y) / 3 + (x + y) % 3;
            }
        } else {
            if (x == 0 && y == 1) {
                steps = 3;
            } else {
                steps = x;
                extra_steps = (y - 2 * x) % 4;
                steps += extra_steps;
                // Remove the effect of all extra steps
                steps += (y - 2 * x - extra_steps) / 2;
            }
        }
        printf("%lld\n", steps);
    }

    return 0;
}
