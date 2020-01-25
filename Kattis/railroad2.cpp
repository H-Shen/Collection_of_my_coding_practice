// https://open.kattis.com/problems/railroad2
//
#include <bits/extc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if ((4 * x + 3 * y) % 2 == 0) {
        cout << "possible";
    } else {
        cout << "impossible";
    }
    cout << endl;
    return 0;
}
