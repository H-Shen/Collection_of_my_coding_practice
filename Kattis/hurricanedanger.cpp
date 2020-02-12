// https://open.kattis.com/problems/hurricanedanger
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using PX = complex<double>;

constexpr int MAXN = 25;
constexpr double EPS = 1e-7;
char s[MAXN];

inline static
int sgn(double x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

double cp(PX a, PX b) { return (conj(a) * b).imag(); }

double dp(PX a, PX b) { return (conj(a) * b).real(); }

double lsp_dist(PX a, PX b, PX p) {
    return dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0 ?
           abs(cp(b - a, p - a) / abs(b - a)) :
           min(abs(a - p), abs(b - p));
}

double ptToLine(PX p, PX v, PX x) {     // x to p + vt
    // Closest point on line: p + v*dp(v, x-p)
    return fabs(cp(v, x - p) / abs(v));
}

struct City {
    string name;
    double dist;
};


int main() {

    PX p, v, pos;
    int n, m;
    double x1, y1, x2, y2, x, y;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        p.real(x1);
        p.imag(y1);
        v.real(x2 - x1);
        v.imag(y2 - y1);
        scanf("%d", &m);
        vector<City> A(m);
        for (int i = 0; i < m; ++i) {
            scanf("%s %lf %lf", s, &x, &y);
            A.at(i).name = s;
            pos.real(x);
            pos.imag(y);
            A.at(i).dist = ptToLine(p, v, pos);
        }
        double min_val = 1000000.0;
        for (int i = 0; i < m; ++i) {
            if (sgn(min_val - A.at(i).dist) > 0) {
                min_val = A.at(i).dist;
            }
        }
        bool first_item = true;
        for (int i = 0; i < m; ++i) {
            if (sgn(min_val - A.at(i).dist) == 0) {
                if (first_item) {
                    first_item = false;
                } else {
                    printf(" ");
                }
                printf("%s", A.at(i).name.c_str());
            }
        }
        printf("\n");
    }
    return 0;
}
