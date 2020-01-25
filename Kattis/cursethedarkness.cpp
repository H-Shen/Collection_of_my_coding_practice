// https://open.kattis.com/problems/cursethedarkness
//
#include <bits/extc++.h>

using namespace std;
constexpr double EPS = 1e-8;

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}


int main() {

    int m, n;
    double x_b, y_b, x_c, y_c, temp;
    bool lightACandle;
    scanf("%d", &m);
    while (m--) {

        lightACandle = false;
        scanf("%lf %lf %d", &x_b, &y_b, &n);
        while (n--) {
            scanf("%lf %lf", &x_c, &y_c);
            if (!lightACandle) {
                temp = (x_b - x_c) * (x_b - x_c) + (y_b - y_c) * (y_b - y_c) - 64.0;
                if (sgn(temp) <= 0) {
                    lightACandle = true;
                }
            }
        }
        // output
        if (lightACandle) {
            printf("light a candle\n");
        } else {
            printf("curse the darkness\n");
        }
    }

    return 0;
}
