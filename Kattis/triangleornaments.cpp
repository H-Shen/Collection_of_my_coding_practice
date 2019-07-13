// https://open.kattis.com/problems/triangleornaments

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

inline
double s(double a, double b, double c)
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

inline
double lengthOfMiddle(double a, double b, double c)
{
    return sqrt(2 * a * a + 2 * b * b - c * c) / 2.0;
}

inline
double l(double a, double b, double c)
{
    return 2.0 * s(a, b, c) / lengthOfMiddle(a, b, c);
}

int main()
{
    int n;
    cin >> n;
    double a, b, c;
    double L = 0.0;
    while (n--)
    {
        cin >> a >> b >> c;
        L += l(a, b, c);
    }
    printf("%.4lf\n", L);
    return 0;
}
