// https://open.kattis.com/problems/robotprotection
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const double EP = 1e-9; // do not use for angles
typedef complex<double> PX;

double cp(PX a, PX b) { return (conj(a) * b).imag(); }

double area(vector<PX> const &P) {
    double a = 0.0;
    for (int i = 0; i < P.size(); i++)
        a += cp(P[i], P[(i + 1) % P.size()]);
    return 0.5 * fabs(a);
}

// Can be used to check if a point is on a line (0)
int ccw(PX a, PX b, PX c) {
    double r = cp(b - a, c - a);
    if (fabs(r) < EP) return 0;
    return r > 0 ? 1 : -1;
}

vector<PX> pts;

void convexHull() {
    if (pts.empty()) return;
    int fi = 0;
    for (int i = 1; i < pts.size(); i++)
        if (pts[i].imag() + EP < pts[fi].imag() ||
            (fabs(pts[i].imag() - pts[fi].imag()) < EP
             && pts[i].real() + EP < pts[fi].real()))
            fi = i;
    swap(pts[0], pts[fi]);
    sort(++pts.begin(), pts.end(), [](PX a, PX b) {
        PX v1 = a - pts[0], v2 = b - pts[0];
        double a1 = arg(v1), a2 = arg(v2);
        // Use smaller epsilon for angles
        if (fabs(a1 - a2) > EP) return a1 < a2;
        return abs(v1) < abs(v2);
    });
    int M = 2;
    for (int i = 2; i < pts.size(); i++) {
        while (M > 1 && ccw(pts[M - 2], pts[M - 1],
                            pts[i]) <= 0)
            M--;
        swap(pts[i], pts[M++]);
    }
    if (M < pts.size()) pts.resize(M);
}

int main() {

    int n;
    double x, y;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<PX>().swap(pts);
        pts.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &x, &y);
            pts.at(i).real(x);
            pts.at(i).imag(y);
        }
        convexHull();
        printf("%.1lf\n", area(pts));
    }
    return 0;
}
