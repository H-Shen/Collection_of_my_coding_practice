// https://open.kattis.com/problems/baconeggsandspam
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s, temp, name;
    map<string, set<string> > A;
    bool firstItem, firstName;
    while (true) {
        A.clear();
        cin >> n;
        cin.get();
        if (n == 0) {
            break;
        }
        while (n--) {
            getline(cin, s);
            istringstream f(s);
            firstItem = true;
            while (getline(f, temp, ' ')) {
                if (firstItem) {
                    firstItem = false;
                    name = temp;
                } else {
                    A[temp].insert(name);
                }
            }
        }
        for (const auto &it : A) {
            firstName = true;
            cout << it.first << " ";
            for (const auto &it0 : it.second) {
                if (firstName) {
                    firstName = false;
                } else {
                    cout << " ";
                }
                cout << it0;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
