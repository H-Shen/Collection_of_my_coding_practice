// https://www.nowcoder.com/practice/841e6f2ee5064452bc59cdb5c19f68e5

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const double PI = acos(-1.0);

int main() {

    int m;
    int x, y, z, x0, y0, z0;
    double R, V;
    cin >> m;
    while (m--) {
        cin >> x >> y >> z >> x0 >> y0 >> z0;
        R = sqrt((x - x0) * (x - x0) +
                 (y - y0) * (y - y0) +
                 (z - z0) * (z - z0));
        V = 4.0 * PI * R * R * R / 3.0;
        printf("%.2lf %.2lf\n", R, V);
    }
    return 0;
}