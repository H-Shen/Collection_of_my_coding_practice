#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

unordered_set<char> P = {'A','H','I','M','O','T','U','V','W','X','Y'};

int main() {
    string s;
    cin >> s;
    string s_copy(s);
    reverse(s_copy.begin(), s_copy.end());
    if (s == s_copy) {
        for (const char &i : s) {
            if (P.find(i) == P.end()) {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}