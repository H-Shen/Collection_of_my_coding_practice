// https://open.kattis.com/problems/tri

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;

    if (b + c == a) cout << a << "=" << b << "+" << c;
    else if (b - c == a) cout << a << "=" << b << "-" << c;
    else if (b * c == a) cout << a << "=" << b << "*" << c;
    else if (b / c == a) cout << a << "=" << b << "/" << c;
    else if (a + b == c) cout << a << "+" << b << "=" << c;
    else if (a - b == c) cout << a << "-" << b << "=" << c;
    else if (a * b == c) cout << a << "*" << b << "=" << c;
    else if (a / b == c) cout << a << "/" << b << "=" << c;
    cout << endl;
    return 0;
}
