// https://open.kattis.com/problems/bijele
#include <bits/extc++.h>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    cout << 1 - a << ' ';
    cout << 1 - b << ' ';
    cout << 2 - c << ' ';
    cout << 2 - d << ' ';
    cout << 2 - e << ' ';
    cout << 8 - f << endl;

    return 0;
}
