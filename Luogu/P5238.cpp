#include <bits/extc++.h>

using namespace std;
using ll = long long;

inline const regex r("^(0|\\-{0,1}[1-9][0-9]*)$");

ll left_ll, right_ll;
int t;

inline static
int parse(const string &s) {
    if (!regex_match(s, r)) {
        return 1;
    }
    try {
        ll temp = stoll(s);
        if (temp >= left_ll && temp <= right_ll) {
            return 0;
        }
    } catch (out_of_range &ex) {}
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> left_ll >> right_ll >> t;
    cin.get();
    string s;
    while (t--) {
        getline(cin, s);
        cout << parse(s) << '\n';
    }
    return 0;
}