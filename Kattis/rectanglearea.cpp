// https://open.kattis.com/problems/rectanglearea

#include <bits/stdc++.h>

using namespace std;

int main() {
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    printf("%.3lf\n", abs(x2-x1)*abs(y2-y1));
    return 0;
}
