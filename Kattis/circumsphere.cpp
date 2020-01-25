// https://open.kattis.com/problems/circumsphere
//
#include <bits/extc++.h>

using namespace std;

inline static
void getSphereCenter(double x1, double y1, double z1,
                     double x2, double y2, double z2,
                     double x3, double y3, double z3,
                     double x4, double y4, double z4,
                     double &x, double &y, double &z) {
    double a11, a12, a13, a21, a22, a23, a31, a32, a33, b1, b2, b3, d, d1, d2, d3;
    a11 = 2 * (x2 - x1);
    a12 = 2 * (y2 - y1);
    a13 = 2 * (z2 - z1);
    a21 = 2 * (x3 - x2);
    a22 = 2 * (y3 - y2);
    a23 = 2 * (z3 - z2);
    a31 = 2 * (x4 - x3);
    a32 = 2 * (y4 - y3);
    a33 = 2 * (z4 - z3);
    b1 = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1 + z2 * z2 - z1 * z1;
    b2 = x3 * x3 - x2 * x2 + y3 * y3 - y2 * y2 + z3 * z3 - z2 * z2;
    b3 = x4 * x4 - x3 * x3 + y4 * y4 - y3 * y3 + z4 * z4 - z3 * z3;
    d = a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 - a11 * a23 * a32 - a12 * a21 * a33 - a13 * a22 * a31;
    d1 = b1 * a22 * a33 + a12 * a23 * b3 + a13 * b2 * a32 - b1 * a23 * a32 - a12 * b2 * a33 - a13 * a22 * b3;
    d2 = a11 * b2 * a33 + b1 * a23 * a31 + a13 * a21 * b3 - a11 * a23 * b3 - b1 * a21 * a33 - a13 * b2 * a31;
    d3 = a11 * a22 * b3 + a12 * b2 * a31 + b1 * a21 * a32 - a11 * b2 * a32 - a12 * a21 * b3 - b1 * a22 * a31;
    x = d1 / d;
    y = d2 / d;
    z = d3 / d;
}


int main() {

    double x1, y1, z1;
    double x2, y2, z2;
    double x3, y3, z3;
    double x4, y4, z4;
    double x, y, z;

    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    cin >> x3 >> y3 >> z3;
    cin >> x4 >> y4 >> z4;
    getSphereCenter(x1, y1, z1,
                    x2, y2, z2,
                    x3, y3, z3,
                    x4, y4, z4,
                    x, y, z);
    printf("%.6f %.6f %.6f\n", x, y, z);

    return 0;
}
