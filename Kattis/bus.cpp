// https://open.kattis.com/problems/bus
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> powerOfTwo = {1};


int main() {

    // pre
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 35; ++i) {
        powerOfTwo.emplace_back(powerOfTwo.back() * 2L);
    }

    // input
    int n;
    cin >> n;
    while (n--) {
        ll k;
        cin >> k;
        cout << powerOfTwo[k] - 1 << endl;
    }

    return 0;
}
