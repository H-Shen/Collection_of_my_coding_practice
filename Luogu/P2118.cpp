#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll a, b, l;
    cin >> a >> b >> l;
    bool first = true;
    double val, temp;
    ll ans_a, ans_b;
    for (ll a_ = 1; a_ <= l; ++a_) {
        for (ll b_ = 1; b_ <= l; ++b_) {
            if (__gcd(a_, b_) == 1 && a_*b >= a*b_) {
                temp = (a_*b-a*b_)*1.0/(b_*b);
                if (first) {
                    first = false;
                    val = temp;
                    ans_a = a_;
                    ans_b = b_;
                }
                else {
                    if (val > temp) {
                        val = temp;
                        ans_a = a_;
                        ans_b = b_;
                    }
                }
            }
        }
    }
    cout << ans_a << ' ' << ans_b << '\n';
    return 0;
}
