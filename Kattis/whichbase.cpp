// https://open.kattis.com/problems/whichbase
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
bool check(const string &s) {
    for (const char &ch : s) {
        if (!isdigit(ch)) {
            return false;
        }
        else if (ch >= '8') {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int kase;
        ll octal;
        string number;
        cin >> kase >> number;
        if (check(number)) {
            octal = stoll(number, nullptr, 8);
        } else {
            octal = 0;
        }
        ll decimal = stoll(number);
        ll hexOutput = stoll(number, nullptr, 16);
        cout << kase << ' ' << octal << ' ' << decimal << ' ' << hexOutput << '\n';
    }

    return 0;
}
