#include <bits/extc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int minutes = - (a * 60 + b) + (c * 60 + d);
    int e = minutes / 60;
    int f = minutes % 60;
    cout << e << ' ' << f << endl;
    return 0;
}