// https://open.kattis.com/problems/smil

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    getline(cin, s);
    vector<int> vec;
    int n = (int)s.size();
    int i = 0;
    while (i < n) {
        if (i <= n - 3) {
            if ( (s[i] == ';' && s[i+1] == '-' && s[i+2] == ')') || (s[i] == ':' && s[i+1] == '-' && s[i+2] == ')') ) {
                vec.emplace_back(i);
                i += 3;
                if (i == n) {
                    break;
                }
                continue;
            }
        }
        if (i <= n - 2) {
            if ((s[i] == ':' && s[i+1] == ')') || (s[i] == ';' && s[i+1] == ')')) {
                vec.emplace_back(i);
                i += 2;
                if (i == n) {
                    break;
                }
                continue;
            }
        }
        ++i;
    }
    for (const auto &j : vec) {
        cout << j << '\n';
    }
    return 0;
}
