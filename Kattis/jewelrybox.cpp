// https://open.kattis.com/problems/jewelrybox
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    double X, Y, h;
    cin >> t;
    while (t--) {
        cin >> X >> Y;
        h = (4.0 * (X + Y - sqrt((X + Y) * (X + Y) - 3.0 * X * Y))) / 24.0;
        printf("%.7lf\n", (X - 2.0 * h) * (Y - 2.0 * h) * h);
    }

    return 0;
}
