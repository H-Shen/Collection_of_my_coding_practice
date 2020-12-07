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
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        reverse(s.begin(), s.end());
        if (s.find("op") == 0) {
            cout << "FILIPINO" << '\n';
        }
        else if (s.find("used") == 0 || s.find("usam") == 0) {
            cout << "JAPANESE" << '\n';
        }
        else {
            cout << "KOREAN" << '\n';
        }
    }

    return 0;
}