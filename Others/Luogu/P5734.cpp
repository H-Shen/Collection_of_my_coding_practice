#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n, op, idx, length;
    cin >> n;
    cin >> s;
    string s_;
    while (n--) {
        cin >> op;
        if (op == 1) {
            cin >> s_;
            s += s_;
            cout << s << '\n';
        } else if (op == 2) {
            cin >> idx >> length;
            s = s.substr(idx, length);
            cout << s << '\n';
        } else if (op == 3) {
            cin >> idx >> s_;
            s = s.substr(0, idx) + s_ + s.substr(idx);
            cout << s << "\n";
        } else {
            cin >> s_;
            auto temp = s.find(s_);
            if (temp == string::npos) {
                cout << "-1\n";
            } else {
                cout << temp << '\n';
            }
        }
    }
    return 0;
}