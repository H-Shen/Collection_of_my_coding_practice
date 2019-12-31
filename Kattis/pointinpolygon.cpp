// https://open.kattis.com/problems/pointinpolygon
//
#include <bits/stdc++.h>

constexpr double EPS = 1e-9;

using namespace std;
using PX = complex<double>;

inline static
bool onSeg(PX p1, PX p2, PX x) {
    return fabs(abs(p2 - p1) - abs(x - p1) - abs(x - p2)) < EPS;
}

inline static
int inPolygon(vector<PX> const &P, PX p) {
    double sum = 0.0;
    int length = static_cast<int>(P.size());
    for (int i = 0; i < length; i++) {
        PX a = P[i], b = P[(i + 1) % P.size()];
        if (onSeg(a, b, p)) {
            return 0;
        }
        sum += arg((a - p) / (b - p));
    }
    return (fabs(fabs(sum) - 2.0 * M_PI) < EPS) ? 1 : -1;
}

int main() {

    int n;
    int m;
    double x, y;
    PX p;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<PX> P(static_cast<size_t>(n));
        for (auto &i : P) {
            scanf("%lf %lf", &x, &y);
            i.real(x);
            i.imag(y);
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%lf %lf", &x, &y);
            p.real(x);
            p.imag(y);
            switch (inPolygon(P, p)) {
                case 0:
                    puts("on");
                    break;
                case 1:
                    puts("in");
                    break;
                default:
                    puts("out");
                    break;
            }
        }
    }

    return 0;
}
