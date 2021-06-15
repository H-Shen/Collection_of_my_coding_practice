// https://open.kattis.com/problems/sorttwonumbers

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << a << ' ' << b << '\n';
    return 0;
}
