// https://open.kattis.com/problems/longestprimesum

#include <bits/extc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        cout << (n/2) << '\n';
    }
    else if (n == 3) {
        cout << 1 << '\n';
    }
    else {
        cout << 1+(n-3)/2 << '\n';
    }
    return 0;
}
