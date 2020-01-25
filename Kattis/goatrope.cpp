// https://open.kattis.com/problems/goatrope
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int x, y, x1, y1, x2, y2;
    double s;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (x1 <= x && x <= x2) {
        if (y <= y1) {
            s = abs(y - y1);
        } else {
            s = abs(y - y2);
        }
    } else if (y1 <= y && y <= y2) {
        if (x <= x1) {
            s = abs(x - x1);
        } else {
            s = abs(x - x2);
        }
    } else if (x < x1 && y < y1) {
        s = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
    } else if (x < x1 && y > y2) {
        s = sqrt((x - x1)*(x - x1) + (y - y2)*(y - y2));
    } else if (x > x2 && y < y1) {
        s = sqrt((x - x2)*(x - x2) + (y - y1)*(y - y1));
    } else {
        s = sqrt((x - x2)*(x - x2) + (y - y2)*(y - y2));
    }
    printf("%.4lf\n", s);

    return 0;
}
