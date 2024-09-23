#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s.at(0) + s.at(1) + s.at(2) == s.at(3) + s.at(4) + s.at(5)) {
            cout << "You are lucky!";
        } else {
            cout << "Wish you good luck.";
        }
        cout << endl;
    }

    return 0;
}