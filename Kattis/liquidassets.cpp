// https://open.kattis.com/problems/liquidassets

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline
string solve(const string &s) {
    string str;
    int n = (int)s.size();
    char last = 0;
    for (int i = 0; i < n; ++i) {
        if (last == 0) {
            last = s[i];
            continue;
        }
        if (s[i] != last) {
            str.push_back(last);
            last = s[i];
        }
    }
    if (last != 0) {
        str.push_back(last);
    }
    string str2;
    n = (int)str.size();
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            if (i == 0 || i == n-1) {
                str2.push_back(str[i]);
            }
        }
        else {
            str2.push_back(str[i]);
        }
    }
    return str2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        if (i > 1) {
            cout << ' ';
        }
        cout << solve(s);
    }
    cout << '\n';
    return 0;
}
