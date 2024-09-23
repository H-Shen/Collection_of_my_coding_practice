#include <bits/stdc++.h>

using namespace std;
const static int N = 4;
const static string MAGICHOLE = "6174";

void handle(string &c) {
    if (c.size() != N) {
        c = string(N - c.size(), '0') + c;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    string a, b, c;
    cin >> a;
    handle(a);

    while (true) {
        unordered_set<char> tmp(a.begin(), a.end());
        if (tmp.size() == 1) {
            cout << a << " - " << a << " = 0000" << endl;
            break;
        }
        sort(a.begin(), a.end());
        b = a;
        reverse(b.begin(), b.end());
        c = to_string(stoi(b) - stoi(a));
        handle(c);
        cout << b << " - " << a << " = " << c << endl;
        a = c;
        if (a == MAGICHOLE) {
            break;
        }
    }
    return 0;
}