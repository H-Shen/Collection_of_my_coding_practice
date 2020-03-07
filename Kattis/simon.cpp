// https://open.kattis.com/problems/simon
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    cin.get();
    while (n--) {
        getline(cin, s);
        if (s.size() >= 11 && s.substr(0, 11) == "simon says ") {
            cout << s.substr(11) << '\n';
        } else {
            cout << '\n';
        }
    }
    return 0;
}
