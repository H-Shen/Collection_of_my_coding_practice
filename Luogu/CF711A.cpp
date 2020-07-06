#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    vector<string> A;
    bool haveAns = false;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[0] == s[1] && s[1] == 'O') {
            haveAns = true;
        }
        if (s[3] == s[4] && s[3] == 'O') {
            haveAns = true;
        }
        A.emplace_back(s);
    }
    if (!haveAns) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        bool hasPrinted = false;
        for (const auto &i : A) {
            if (!hasPrinted && i[0] == i[1] && i[1] == 'O') {
                hasPrinted = true;
                cout << "++|" << i[3] << i[4] << '\n';
            }
            else if (!hasPrinted && i[3] == i[4] && i[3] == 'O') {
                hasPrinted = true;
                cout << i[0] << i[1] << "|++" << '\n';
            } else {
                cout << i << '\n';
            }
        }
    }
    return 0;
}
