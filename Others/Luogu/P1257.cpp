#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 10005;

struct Point {
    double x, y;
};
Point A[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &A[i].x, &A[i].y);
    }
    double dist = 1000000000.0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dist = min(dist, sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x)+(A[i].y-A[j].y)*(A[i].y-A[j].y)));
        }
    }
    printf("%.4lf\n", dist);

    return 0;
}
