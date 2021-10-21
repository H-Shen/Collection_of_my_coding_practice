// https://open.kattis.com/problems/grading

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    int a, b, c, d, e, val;
    cin >> a >> b >> c >> d >> e >> val;
    if (val < e) {
        cout << 'F';
    } else if (val < d) {
        cout << 'E';
    } else if (val < c) {
        cout << 'D';
    } else if (val < b) {
        cout << 'C';
    } else if (val < a) {
        cout << 'B';
    } else {
        cout << 'A';
    }
    cout << '\n';
    return 0;
}
