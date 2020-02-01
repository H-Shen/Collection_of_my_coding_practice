// https://open.kattis.com/problems/areyoulistening
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int cx, cy, n;
double min_radius = 0x3f3f3f3f;

struct Circle {
    int x;
    int y;
    int r;
};

double solve(const Circle &A, const Circle &B, const Circle &C) {
    double s1;
    int temp = (A.x - cx)*(A.x - cx)+(A.y - cy)*(A.y - cy);
    if (temp <= A.r*A.r) {
        s1 = 0.0;
    } else {
        s1 = sqrt(temp) - A.r * 1.0;
    }
    double s2;
    temp = (B.x - cx)*(B.x - cx)+(B.y - cy)*(B.y - cy);
    if (temp <= B.r*B.r) {
        s2 = 0.0;
    } else {
        s2 = sqrt(temp) - B.r * 1.0;
    }
    double s3;//
    temp = (C.x - cx)*(C.x - cx)+(C.y - cy)*(C.y - cy);
    if (temp <= C.r*C.r) {
        s3 = 0.0;
    } else {
        s3 = sqrt(temp) - C.r * 1.0;
    }
    return max(max(s1, s2), s3);
}

int main() {

    scanf("%d %d %d", &cx, &cy, &n);
    vector<Circle> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &A.at(i).x, &A.at(i).y, &A.at(i).r);
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                min_radius = min(min_radius, solve(A.at(i), A.at(j), A.at(k)));
            }
        }
    }
    printf("%d\n", (int)min_radius);
    return 0;
}
