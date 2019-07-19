// https://www.nowcoder.com/practice/171278d170c64d998ab342b3b40171bb

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
