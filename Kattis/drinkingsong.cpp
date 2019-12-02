// https://open.kattis.com/problems/drinkingsong
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;
    bool firstItem = true;
    for (int i = n; i >= 1; --i) {
        if (!firstItem) {
            cout << endl;
        }
        if (i == 1) {
            cout << "1 bottle of " << s << " on the wall, 1 bottle of " << s << "." << endl;
            cout << "Take it down, pass it around, no more bottles of " << s << "." << endl;
        } else if (i == 2) {
            cout << "2 bottles of " << s << " on the wall, " << "2 bottles of " << s << "." << endl;
            cout << "Take one down, pass it around, 1 bottle of " << s << " on the wall." << endl;
        } else {
            cout << i << " bottles of " << s << " on the wall, " << i << " bottles of " << s << "." << endl;
            cout << "Take one down, pass it around, " << i - 1 << " bottles of " << s << " on the wall." << endl;
        }
        if (firstItem) {
            firstItem = false;
        }
    }

    return 0;
}
