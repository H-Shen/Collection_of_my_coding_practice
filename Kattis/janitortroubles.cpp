// https://open.kattis.com/problems/janitortroubles
//
#include <bits/stdc++.h>

using namespace std;

double area(double a, double b, double c, double d) {
    double p = (a + b + c + d) / 2.0;
    return sqrt((p - a)*(p - b)*(p - c)*(p - d));
}

int main() {

    double a, b, c, d;
    cin >> a >> b >> c >> d;
    printf("%.8lf\n", area(a, b, c, d));

    return 0;
}
