// https://acpc21d1.kattis.com/problems/wonkypizza

#include <bits/extc++.h>

using namespace std;
using ll = long long;

double a, b, S;
int n;
double f_0;

double F(double theta) {
    return (a*theta+2*M_PI*b)*(a*theta+2*M_PI*b)*(a*theta+2*M_PI*b)/(24*M_PI*M_PI*a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b >> n;
    if (a == 0) {
        for (int i = 1; i <= n-1; ++i) {
            printf("%.6lf\n", 2*M_PI/n*i);
        }
        return 0;
    }
    f_0 = F(0);
    S = F(2*M_PI) - f_0;
    for (int i = 1; i <= n-1; ++i) {
        printf("%.6lf\n", (pow((S*i/n + f_0) * 24*M_PI*M_PI*a, 1.0/3)-2*M_PI*b)/a);
    }
    return 0;
}
