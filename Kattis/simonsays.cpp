// https://open.kattis.com/problems/simonsays
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cin.get();
    string s;
    while (n--) {
        getline(cin, s);
        if (s.size() >= 10 && s.substr(0, 10) == "Simon says") {
            cout << s.substr(10) << '\n';
        }
    }
    return 0;
}
