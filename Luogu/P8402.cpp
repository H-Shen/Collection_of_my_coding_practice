#include <bits/stdc++.h>

using namespace std;

string solve(const string&s) {
    string s1, s2;
    int i = 0;
    int n = (int)s.size();
    for (; s[i] != '+' && s[i] != '-'; ++i) {
        s1.push_back(s[i]);
    }
    if (s[i] == '+') {
        s1 += " tighten ";
    }
    else {
        s1 += " loosen ";
    }
    ++i;
    for (; i < n; ++i) {
        s2.push_back(s[i]);
    }
    return s1 + s2;
}

int main() {
    string s;
    cin >> s;
    string str;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            str.push_back(s[i]);
            continue;
        }
        if (isalpha(s[i]) && isdigit(s[i-1])) {
            cout << solve(str) << '\n';
            str.clear();
        }
        str.push_back(s[i]);
    }
    if (!str.empty()) {
        cout << solve(str) << '\n';
    }
    return 0;
}