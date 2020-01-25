// https://open.kattis.com/problems/jabuke
//
#include <bits/extc++.h>

using namespace std;
constexpr double EP = 1e-8;
constexpr size_t vertices = 3;
using PX = complex<double>;

bool onSeg(PX p1, PX p2, PX x) {
    // Sometimes 1e-14 may be a better choice here
    return fabs(abs(p2 - p1) - abs(x - p1) - abs(x - p2)) < EP;
}

bool inPolygon(vector<PX> const &P, PX p) {
    double sum = 0.0;
    int len = static_cast<int>(P.size());
    for (int i = 0; i < len; i++) {
        PX a = P[i], b = P[(i + 1) % len];
        // to exclude edges, MUST return false
        if (onSeg(a, b, p)) return true;
        sum += arg((a - p) / (b - p));
    }
    // Use 1e-14 for angle
    return fabs(fabs(sum) - 2.0 * M_PI) < EP;
}

double getArea(double xA, double xB, double xC, double yA, double yB, double yC) {
    return fabs(xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB)) / 2.0;
}

int main() {

    double xA, xB, xC, yA, yB, yC, x, y;
    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;

    vector<PX> P(vertices);
    P.at(0).real(xA);
    P.at(0).imag(yA);
    P.at(1).real(xB);
    P.at(1).imag(yB);
    P.at(2).real(xC);
    P.at(2).imag(yC);

    int q;
    int counter = 0;
    PX point;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        point.real(x);
        point.imag(y);
        if (inPolygon(P, point)) {
            ++counter;
        }
    }
    printf("%.1f\n%d\n", getArea(xA, xB, xC, yA, yB, yC), counter);
    return 0;
}
