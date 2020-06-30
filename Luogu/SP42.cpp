#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    string a, b, sum;
    ll a_rev, b_rev, sum_rev;
    while (t--) {
        cin >> a >> b;
        reverse(a.begin(), a.end());
        a_rev = stoll(a);
        reverse(b.begin(), b.end());
        b_rev = stoll(b);
        sum = to_string(a_rev + b_rev);
        reverse(sum.begin(), sum.end());
        sum_rev = stoll(sum);
        cout << sum_rev << '\n';
    }

    return 0;
}
