#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    vector<string> A;

    while (true) {
        cin >> s;
        if (s == ".") {
            break;
        }
        A.push_back(s);
    }

    string a, b;
    try {
        a = A.at(1);
    } catch (...) {
        cout << "Momo... No one is for you ..." << endl;
        return 0;
    }

    try {
        b = A.at(13);
    } catch (...) {
        cout << a << " is the only one for you..." << endl;
        return 0;
    }

    cout << a << " and " << b << " are inviting you to dinner..." << endl;

    return 0;
}