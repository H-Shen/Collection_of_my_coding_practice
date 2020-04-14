#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    string s;
    cin >> s;
    if (s[0] == 'M' && s[1] == 'D' && s[2] == 'A') {
        int number = -1;
        for (auto iter = s.crbegin(); iter != s.crend(); ++iter) {
            if (isdigit(*iter)) {
                number = *iter - '0';
                break;
            }
        }
        if (number == 1 || number == 9) {
            cout << "1 0 0 0 0" << endl;
        } else if (number == 2 || number == 8) {
            cout << "0 1 0 0 0" << endl;
        } else if (number == 3 || number == 7) {
            cout << "0 0 1 0 0" << endl;
        } else if (number == 4 || number == 6) {
            cout << "0 0 0 1 0" << endl;
        } else if (number == 5 || number == 0) {
            cout << "0 0 0 0 1" << endl;
        }
    } else {
        cout << "1 1 1 1 1" << endl;
    }

    return 0;
}