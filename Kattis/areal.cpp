// https://open.kattis.com/problems/areal
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ll a;
    cin >> a;
    printf("%.6lf\n", sqrt((double)a) * 4.0);
    return 0;
}