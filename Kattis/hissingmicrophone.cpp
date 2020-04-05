// https://open.kattis.com/problems/hissingmicrophone
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    if (strstr(s.c_str(), "ss")) {
        cout << "hiss" << '\n';
    } else {
        cout << "no hiss" << '\n';
    }

    return 0;
}
