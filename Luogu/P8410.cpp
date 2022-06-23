#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a,b,tot;
int n;
string s;

int main() {
    cin >> n >> a >> b;
    cin.get();
    while (getline(cin, s)) {
        if (s == "/oh") tot += a;
        else if (s == "/hsh") tot += b;
    }
    cout << tot << '\n';
    return 0;
}