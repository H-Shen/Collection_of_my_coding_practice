// https://open.kattis.com/problems/aboveaverage

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const double eps = 1e-8;

inline
int sgn(double a)
{
    if (a > eps) return 1;
    if (a < -eps) return -1;
    return 0;
}

int main()
{
    int n, m, cnt;
    cin >> n;
    double s, avg;
    while (n--)
    {
        cin >> m;
        s = 0.0;
        vector <double> A(m);
        for (auto &&val : A)
        {
            cin >> val;
            s += val;
        }
        avg = s / m;
        cnt = 0;
        for (const auto &val : A)
        {
            if (sgn(val - avg) > 0)
            {
                ++cnt;
            }
        }
        printf("%.3lf%%\n", cnt * 1.0 / m * 100.0);
    }
    return 0;
}
