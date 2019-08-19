#include <bits/stdc++.h>

using namespace std;

const int maxn = 4;

int main() {
    ios_base::sync_with_stdio(false);
    string s, s_rev, s_res;
    int res;
    cin >> s;
    s = string(4 - s.size(), '0') + s;

    unordered_set<char> s_unique(s.begin(), s.end());
    if (s_unique.size() == 1) {
        cout << s << " - " << s << " = 0000" << endl;
        return 0;
    }

    while (true) {

        sort(s.begin(), s.end());
        s_rev = s;

        reverse(s_rev.begin(), s_rev.end());
        res = stoi(s_rev) - stoi(s);
        s_res = to_string(res);
        s_res = string(4 - s_res.size(), '0') + s_res;

        cout << s_rev << " - " << s << " = " << s_res << endl;

        if (res == 6174) {
            break;
        }
        s = s_res;
    }
    return 0;
}