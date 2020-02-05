// https://open.kattis.com/problems/combinationlock
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int position, a, b, c;
    while (true) {
        scanf("%d %d %d %d", &position, &a, &b, &c);
        if (position == 0 && a == 0 && b == 0 && c == 0) {
            break;
        }
        int interval = 0;
        interval += 80;
        while (position != a) {
            ++interval;
            --position;
            if (position == -1) {
                position = 39;
            }
        }
        interval += 40;
        while (position != b) {
            ++interval;
            ++position;
            if (position == 40) {
                position = 0;
            }
        }
        while (position != c) {
            ++interval;
            --position;
            if (position == -1) {
                position = 39;
            }
        }
        printf("%d\n", interval * 9);
    }

    return 0;
}
