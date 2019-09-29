// https://open.kattis.com/problems/parket
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int R, B, a_plus_b;
    cin >> R >> B;
    a_plus_b = (R - 4) / 2;
    for (int a = 1; a < a_plus_b; ++a) {
        int b = a_plus_b - a;
        if (a * b == B) {
            a += 2;
            b += 2;
            cout << max(a, b) <<  ' ' << min(a, b) << endl;
            return 0;
        }
    }

    return 0;
}
