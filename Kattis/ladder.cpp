// https://open.kattis.com/problems/ladder
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);

inline int sgn(double a)

{
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int h, v;
    double s;
    cin >> h >> v;
    double v_rad = v * pi / 180.0;
    s = h / sin(v_rad);

    if (sgn(s - (double)((int)s)) == 0)
    {
        cout << (int)s << endl;
    }
    else
    {
        cout << (int)s + 1 << endl;
    }

    return 0;
}
