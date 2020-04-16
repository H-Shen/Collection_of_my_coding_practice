// https://open.kattis.com/problems/greedypolygons
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

double area(int n, int l) {
    return n*l*l*1.0/(4.0*tan(M_PI/n));
}

double solve(int n, int l, int d, int g) {
    return l*d*n*1.0*g+M_PI*d*d*g*g + area(n, l);
}

int main() {
    int t, n, l, d, g;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &l, &d, &g);
        printf("%.6lf\n", solve(n, l, d, g));
    }
    return 0;
}
