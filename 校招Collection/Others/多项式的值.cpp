// https://www.nowcoder.com/practice/13634a38c0eb4b9db8701953ed453567

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {

    int m, n;
    ll x, x_mul;
    cin >> m;
    while (m--) {
        cin >> n;
        vector<ll> A(static_cast<unsigned long>(n + 1));
        for (auto &&i : A) {
            cin >> i;
        }
        cin >> x;
        x_mul = x;
        ll sum = 0;
        for (size_t i = 0; i != A.size(); ++i) {
            if (i == 0) {
                sum = A.at(i);
            } else {
                sum += A.at(i) * x_mul;
                x_mul *= x;
            }
        }
        cout << sum << endl;
    }

    return 0;
}