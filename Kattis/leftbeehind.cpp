// https://open.kattis.com/problems/leftbeehind
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int x, y;
    while (~scanf("%d %d", &x, &y)) {
        if (x == 0 && y == 0) {
            break;
        }
        if (x + y == 13) {
            printf("Never speak again.\n");
        } else if (x > y) {
            printf("To the convention.\n");
        } else if (x == y) {
            printf("Undecided.\n");
        } else {
            printf("Left beehind.\n");
        }
    }

    return 0;
}
