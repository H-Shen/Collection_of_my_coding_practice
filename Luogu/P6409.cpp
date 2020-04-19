#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    getline(cin, s);
    int len = static_cast<int>(s.size());

    int i = 0;
    while (i < len) {
        if (i + 3 <= len) {
            if (s.substr(i, 3) == "epe") {
                cout << "e";
                i += 3;
            } else if (s.substr(i, 3) == "apa") {
                cout << "a";
                i += 3;
            } else if (s.substr(i, 3) == "ipi") {
                cout << "i";
                i += 3;
            } else if (s.substr(i, 3) == "opo") {
                cout << "o";
                i += 3;
            } else if (s.substr(i, 3) == "upu") {
                cout << "u";
                i += 3;
            } else {
                cout << s[i++];
            }
        } else {
            cout << s[i++];
        }
    }
    cout << '\n';

    return 0;
}
