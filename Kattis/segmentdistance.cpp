// https://open.kattis.com/problems/segmentdistance
//
#include <bits/extc++.h>

using namespace std;
const double EP = 1e-9;
using PX = complex<double>;

double cp(PX a, PX b) {
    return (conj(a) * b).imag();
}

double dp(PX a, PX b) {
    return (conj(a) * b).real();
}

int ccw(PX a, PX b, PX c) {
    double r = cp(b - a, c - a);
    if (fabs(r) < EP) {
        return 0;
    }
    return (r > 0) ? 1 : -1;
}

bool onSeg(PX p1, PX p2, PX x) {
    return fabs(abs(p2 - p1) - abs(x - p1) - abs(x - p2)) < EP;
}

double euclideanDistance(const PX &a, const PX &b) {
    return sqrt((a.real() - b.real()) * (a.real() - b.real()) +
                (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

double lsp_dist(PX a, PX b, PX p) {
    return dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0 ?
           abs(cp(b - a, p - a) / abs(b - a)) :
           min(abs(a - p), abs(b - p));
}

bool segIntersect(PX p1, PX p2, PX q1, PX q2) {
    int o1 = ccw(p1, p2, q1);
    int o2 = ccw(p1, p2, q2);
    int o3 = ccw(q1, q2, p1);
    int o4 = ccw(q1, q2, p2);
    if (o1 != o2 && o3 != o4) return true;
    // p1, p2 and q1 are colinear and q1 on p1p2
    if (o1 == 0 && onSeg(p1, p2, q1)) return true;
    // p1, p2 and q1 are colinear and q2 on p1p2
    if (o2 == 0 && onSeg(p1, p2, q2)) return true;
    // q1, q2 and p1 are colinear and p1 on q1q2
    if (o3 == 0 && onSeg(q1, q2, p1)) return true;
    // q1, q2 and p2 are colinear and p2 on q1q2
    return o4 == 0 && onSeg(q1, q2, p2);
}

int main() {

    int n;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    bool segmentOneIsAPoint;
    bool segmentTwoIsAPoint;
    double distance;
    PX A, B, C, D;

    scanf("%d", &n);
    while (n--) {

        segmentOneIsAPoint = false;
        segmentTwoIsAPoint = false;
        distance = 0.0;

        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4,
              &y4);

        A.real(x1);
        A.imag(y1);
        B.real(x2);
        B.imag(y2);
        C.real(x3);
        C.imag(y3);
        D.real(x4);
        D.imag(y4);

        if (x1 == x2 && y1 == y2) {
            segmentOneIsAPoint = true;
        }
        if (x3 == x4 && y3 == y4) {
            segmentTwoIsAPoint = true;
        }
        // Case 1: PX to PX
        if (segmentOneIsAPoint && segmentTwoIsAPoint) {
            distance = euclideanDistance(A, C);
        }
        // Case 2: PX to Segment
        else if (segmentOneIsAPoint) {
            if (onSeg(C, D, A)) {
                distance = 0.0;
            } else {
                distance = lsp_dist(C, D, A);
            }
        }
        // Case 3: Segment to PX
        else if (segmentTwoIsAPoint) {
            if (onSeg(A, B, C)) {
                distance = 0.0;
            } else {
                distance = lsp_dist(A, B, C);
            }
        }
        // Case 4: Segment to Segment
        else {
            if (segIntersect(A, B, C, D)) {
                distance = 0.0;
            } else {
                distance = min(min(min(
                        lsp_dist(A, B, C),
                        lsp_dist(A, B, D)),
                        lsp_dist(C, D, A)),
                        lsp_dist(C, D, B));
            }
        }
        printf("%.2lf\n", distance);
    }

    return 0;
}
