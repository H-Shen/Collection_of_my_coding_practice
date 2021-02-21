// https://open.kattis.com/problems/methodicmultiplication

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(string a) {
    if (a == "0") return 0;
    return count(a.begin(), a.end(), 'S');
}

int main() {

    string a, b;
    cin >> a >> b;
    int c = solve(a) * solve(b);
    if (c == 0) cout << 0 << '\n';
    else {
        string s;
        for (int i = 0; i < c; ++i) {
            s += "S(";
        }
        s += "0";
        for (int i = 0; i < c; ++i) {
            s += ")";
        }
        cout << s << '\n';
    }

    return 0;
}
