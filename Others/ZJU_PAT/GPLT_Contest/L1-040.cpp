#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    char sx;
    double h;
    cin >> n;
    getchar();

    while (n--) {
        cin >> sx >> h;
        if (sx == 'M') {
            printf("%.2f\n", h / 1.09);
        } else {
            printf("%.2f\n", h * 1.09);
        }
    }
    return 0;
}