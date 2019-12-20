// https://ac.nowcoder.com/acm/contest/1001/B

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto &&i : A) {
        cin >> i;
    }
    ll ans{0};
    sort(begin(A), end(A));
    for (int i = 0; i < n / 2; ++i) {
        ans += A.at(n - i - 1) - A.at(i);
    }
    cout << ans << endl;

    return 0;
}