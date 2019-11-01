// https://open.kattis.com/problems/pieceofcake2
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, h, v;
    cin >> n >> h >> v;
    int a = h * v * 4;
    int b = (n - v) * h * 4;
    int c = (n - h) * v * 4;
    int d = (n - v) * (n - h) * 4;
    cout << max(a, max(b, max(c, d))) << endl;

    return 0;
}
