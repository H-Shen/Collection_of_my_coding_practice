// https://open.kattis.com/problems/jobexpenses
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    ll val;
    ll sum{0};
    cin >> n;
    while (n--) {
        cin >> val;
        if (val < 0) {
            sum += -val;
        }
    }
    cout << sum << endl;

    return 0;
}
