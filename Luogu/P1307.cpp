#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    long long a;
    cin >> a;
    if (a == 0) {
        cout << a << '\n';
    } else {
        bool is_neg = (a < 0);
        if (is_neg) a = -a;
        string s = to_string(a);
        reverse(s.begin(), s.end());
        while (s.size() > 1 && s.front() == '0') {
            s = s.substr(1);
        }
        if (is_neg) cout << "-";
        cout << s << '\n';
    }

    return 0;
}
