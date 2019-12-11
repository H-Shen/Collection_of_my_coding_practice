// https://open.kattis.com/problems/boatparts
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int p, n;
    cin >> p >> n;
    string s;
    unordered_set<string> A;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        A.insert(s);
        if (p == static_cast<int>(A.size())) {
            cout << (i + 1) << endl;
            return 0;
        }
    }
    cout << "paradox avoided" << endl;

    return 0;
}
