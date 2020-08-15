#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 5;

vector<ll> temp;

int main() {

    string s;
    for (int i = 1; i <= MAXN; ++i) {
        s = string(i, '4') + string(i, '7');
        do {
            temp.emplace_back(stoll(s));
        } while (next_permutation(s.begin(), s.end()));
    }
    ll n;
    cin >> n;
    cout << *lower_bound(temp.begin(), temp.end(), n) << '\n';

    return 0;
}