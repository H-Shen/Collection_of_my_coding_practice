#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int l, r, temp;
    scanf("%d %d", &l, &r);
    int counter = 0;
    for (int i = l; i <= r; ++i) {
        temp = i;
        while (temp > 0) {
            if (temp % 10 == 2) {
                ++counter;
            }
            temp /= 10;
        }
    }
    printf("%d\n", counter);

    return 0;
}