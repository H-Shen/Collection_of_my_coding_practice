// https://open.kattis.com/problems/armcoordination

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll x,y,r;
    cin >> x >> y >> r;
    cout << x-r << ' ' << y+r << '\n';
    cout << x+r << ' ' << y+r << '\n';
    cout << x+r << ' ' << y-r << '\n';
    cout << x-r << ' ' << y-r << '\n';
    return 0;
}
