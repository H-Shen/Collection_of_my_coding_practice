#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    char ch;
    string s;
    cin >> n >> ch;
    getchar();
    getline(cin, s);

    int len = s.size();
    if (len >= n) {
        s = s.substr(s.size() - n);
    } else {
        string tmp(n - len, ch);
        s = tmp + s;
    }
    cout << s << endl;
    return 0;
}