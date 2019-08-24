// https://open.kattis.com/problems/inversefactorial
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    // pre-Calculation
    unordered_map<string, ll> A;
    ll s = 1;
    for (ll i = 1; i <= 20; ++i) {
        s *= i;
        A[to_string(s)] = i;
    }

    // input
    string result;
    cin >> result;

    // output
    if (A.find(result) != A.end()) {
        cout << A[result] << endl;
    } else {
        int length = static_cast<int>(result.size());
        int n = 1;
        double ans = 1.0;
        while (true) {
            ans += log10(n);
            if (floor(ans) == length) {
                cout << n << endl;
                break;
            }
            ++n;
        }
    }
    return 0;
}
