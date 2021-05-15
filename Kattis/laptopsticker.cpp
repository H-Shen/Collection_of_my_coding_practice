// https://open.kattis.com/problems/laptopsticker

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;
    if (ws <= wc - 2 && hs <= hc - 2) {
        cout << 1;
    } else {
        cout << 0;
    }
    cout << '\n';

    return 0;
}
