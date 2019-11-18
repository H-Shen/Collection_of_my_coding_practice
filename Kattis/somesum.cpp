// https://open.kattis.com/problems/somesum
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, b, s;
    cin >> n;
    bool even = false;
    bool odd = false;
    for (int a = 1; a <= 101 - n; ++a) {
        b = a + n - 1;
        s = (a + b) * n / 2;
        if (s % 2 == 0) {
            even = true;
        } else {
            odd = true;
        }
        if (even && odd) {
            break;
        }
    }
    if (even && odd) {
        cout << "Either" << endl;
    } else if (even) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }

    return 0;
}
