// https://open.kattis.com/problems/estimatingtheareaofacircle
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
const double pi = acos(-1.0);

int main()
{
    double r;
    int m, c;
    double s1, s2;
    while (cin >> r >> m >> c)
    {
        if (m == 0)
        {
            break;
        }
        s1 = pi * r * r;
        s2 = 4.0 * r * r * c / m;
        printf("%.5lf %.5lf\n", s1, s2);
    }
    return 0;
}
