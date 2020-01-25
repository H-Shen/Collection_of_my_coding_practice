// https://open.kattis.com/problems/heartrate
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int n;
    double b, p, bpm, abpm;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf", &b, &p);
        bpm = 60 * b / p;
        abpm = 60 * 1.0 / p;
        printf("%.4lf %.4lf %.4lf\n", bpm - abpm, bpm, bpm + abpm);
    }

    return 0;
}
