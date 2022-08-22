// https://open.kattis.com/problems/gcd

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    cout << gcd(m,n) << '\n';
    return 0;
}
