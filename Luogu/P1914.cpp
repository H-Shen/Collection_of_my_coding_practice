#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

string solve(string s, int n) {
    for (auto &ch : s) {
        for (int i = 0; i < n; ++i) {
            ++ch;
            if (ch < 'a') {
                ch = 'z';
            } else if (ch > 'z') {
                ch = 'a';
            }
        }
    }
    return s;
}

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n) << '\n';
    return 0;
}
