// https://open.kattis.com/problems/digits
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string temp;
    while (true) {
        cin >> s;
        if (s == "END") {
            break;
        }
        int counter = 1;
        while (true) {
            temp = to_string(s.size());
            if (temp == s) {
                break;
            }
            ++counter;
            s = temp;
        }
        cout << counter << '\n';
    }

    return 0;
}
