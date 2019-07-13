// https://open.kattis.com/problems/oddities
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

const double eps = 1e-8;

inline int sgn(double a)

{
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        if (val % 2 == 0)
        {
            cout << val << " is even" << endl;
        }
        else
        {
            cout << val << " is odd"  << endl;
        }
    }

    return 0;
}
