// https://www.nowcoder.com/practice/af1d874fb54d4989ae868959bdda9894

#include <cstdio>
#include <iostream>

using namespace std;

int main() {

    int m, x;
    double y;
    cin >> m;
    while (m--) {
        cin >> x;
        if (x >= 0 && x < 2) {
            y = -x + 2.5;
        } else if (x >= 2 && x < 4) {
            y = 2 - 1.5 * (x - 3) * (x - 3);
        } else {
            y = x * 0.5 - 1.5;
        }
        printf("y=%.1lf\n", y);
    }

    return 0;
}