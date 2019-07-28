#include <stdio.h>

typedef long long ll;
typedef struct {
    ll x, y, z;
} Point;

void getExpr(Point p1, Point p2, Point p3, ll *a, ll *b, ll *c, ll *d) {
    *a = ((p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y));
    *b = ((p2.z - p1.z) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.z - p1.z));
    *c = ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));
    *d = (0 - ((*a) * p1.x + (*b) * p1.y + (*c) * p1.z));
}

int main(void) {

    int n;
    ll A = 0, B = 0, C = 0, D = 0;

    scanf("%d", &n);
    while (n--) {

        Point p0, p1, p2, p3;
        scanf("%lld %lld %lld", &p0.x, &p0.y, &p0.z);
        scanf("%lld %lld %lld", &p1.x, &p1.y, &p1.z);
        scanf("%lld %lld %lld", &p2.x, &p2.y, &p2.z);
        scanf("%lld %lld %lld", &p3.x, &p3.y, &p3.z);

        //Ax + By + Cz + D == 0
        getExpr(p0, p1, p2, &A, &B, &C, &D);
        if (A * p3.x + B * p3.y + C * p3.z + D == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
