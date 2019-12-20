#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, x, y;
    bool haveAns = false;
    cin >> n;
    for (x = 1; x * x <= n; ++x) {
        y = static_cast<int>(sqrt(n - x * x));
        if (x * x + y * y == n && x <= y) {
            haveAns = true;
            cout << x << ' ' << y << endl;
        }
    }
    if (!haveAns) {
        cout << "No Solution" << endl;
    }
    return 0;
}