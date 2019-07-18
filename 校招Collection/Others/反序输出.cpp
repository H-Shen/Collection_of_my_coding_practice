#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    while (getline(cin, s)) {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}
