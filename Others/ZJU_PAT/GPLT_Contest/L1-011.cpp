#include <bits/stdc++.h>

using namespace std;

int main() {

    string a, b, c;
    getline(cin, a);
    getline(cin, b);

    unordered_set<char> A(b.begin(), b.end());
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        if (A.find(a[i]) == A.end()) {
            c = c + a[i];
        }
    }
    cout << c << endl;

    return 0;
}