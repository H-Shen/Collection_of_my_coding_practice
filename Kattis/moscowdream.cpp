// https://open.kattis.com/problems/moscowdream
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (a == 0 || b == 0 || c == 0 || n < 3) {
        cout << "NO" << endl;
        return 0;
    }
    --a;
    --b;
    --c;
    n -= 3;
    if (a + b + c < n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
