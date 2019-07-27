// https://open.kattis.com/problems/pizza2

#include<bits/stdc++.h>

using namespace std;

int main() {
    double r, c;
    cin >> r >> c;
    printf("%.6lf\n", (r - c) * (r - c) / (r * r) * 100.0);
    return 0;
}
