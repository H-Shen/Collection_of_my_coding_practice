// https://open.kattis.com/problems/qaly
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    double s = 0;
    double a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        s += a * b;
    }
    printf("%.3f\n", s);
    return 0;
}
