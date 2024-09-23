// https://www.nowcoder.com/practice/62caec1507ac47548670a31c5ff8a8b7

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    for (const char &ch : s) {
        if (ch == ' ') {
            cout << "%20";
        } else {
            cout << ch;
        }
    }
    cout << endl;

    return 0;
}