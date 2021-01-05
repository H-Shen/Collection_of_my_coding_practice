#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

bool isPalindrome(ll x) {
    vector<int> temp;
    while (x > 0) {
        temp.emplace_back(x % 10);
        x /= 10;
    }
    int length = (int)temp.size();
    for (int i = 0; i < length / 2; ++i) {
        if (temp.at(i) != temp.at(length - 1 - i)) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, iteration;
    ll n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        iteration = 0;
        while (!isPalindrome(n)) {
            s = to_string(n);
            reverse(s.begin(), s.end());
            n += stoll(s);
            ++iteration;
        }
        cout << iteration << ' ' << n << '\n';
    }

    return 0;
}