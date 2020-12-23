#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
        if (s == "0") cout << "No" << '\n';
        else if (s == "1") cout << "Yes" << '\n';
        return 0;
    }
    bool haveAns = true;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (s.at(i) == '0' && s.at(i + 1) == '0') {
                haveAns = false;
                break;
            }
            if (s.at(i) == '1' && s.at(i + 1) == '1') {
                haveAns = false;
                break;
            }
        } else if (i == n - 1) {
            if (s.at(i) == '0' && s.at(i - 1) == '0') {
                haveAns = false;
                break;
            }
            if (s.at(i) == '1' && s.at(i - 1) == '1') {
                haveAns = false;
                break;
            }
        } else {
            if (s.at(i) == '0' && s.at(i - 1) == '0' && s.at(i + 1) == '0') {
                haveAns = false;
                break;
            }
            if (s.at(i) == '1' && (s.at(i - 1) == '1' || s.at(i + 1) == '1')) {
                haveAns = false;
                break;
            }
        }
    }
    if (haveAns) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << '\n';

    return 0;
}