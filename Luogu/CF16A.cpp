#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n, m;
    string s;
    cin >> n >> m;
    vector<string> A;
    string last_row;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        unordered_set<char> unset(s.begin(), s.end());
        if (unset.size() != 1) {
            cout << "NO" << '\n';
            return 0;
        }
        if (last_row.empty()) {
            last_row = s;
        } else if (s == last_row) {
            cout << "NO" << '\n';
            return 0;
        } else {
            last_row = s;
        }
    }
    cout << "YES" << '\n';

    return 0;
}