#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int t, n;
    string s;
    cin >> t;
    bool have_ans;
    while (t--) {
        cin >> n >> s;
        have_ans = false;
        for (int i = 0; i < n; ++i) {
            if (s.at(i) == '8') {
                if (n - i >= 11) {
                    have_ans = true;
                    break;
                }
            }
        }
        if (have_ans) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}