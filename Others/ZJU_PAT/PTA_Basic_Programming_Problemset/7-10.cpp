#include <iostream>

using namespace std;

int main() {

    int y, t, s;
    double w;
    cin >> y >> t;

    if (y >= 5) {
        s = 50;
    } else {
        s = 30;
    }

    if (t <= 40) {
        w = s * t;
    } else {
        w = s * 40 + 1.5 * s * (t - 40);
    }
    printf("%.2f\n", w);
    return 0;
}
