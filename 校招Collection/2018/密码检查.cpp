// https://www.nowcoder.com/practice/f2fbd8f61c564ca0b5feaa63ab42dae5

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    int combination;
    bool includeDigit;
    bool includeUpper;
    bool includeLower;

    cin >> n;

    while (n--) {

        cin >> s;

        // Length
        if (s.size() < 8) {
            cout << "NO" << endl;
            continue;
        }
        // First Character
        if (isdigit(s[0])) {
            cout << "NO" << endl;
            continue;
        }

        combination = 0;
        includeDigit = false;
        includeUpper = false;
        includeLower = false;
        for (const auto &ch : s) {
            if (isdigit(ch) && !includeDigit) {
                includeDigit = true;
                ++combination;
            }
            if (isupper(ch) && !includeUpper) {
                includeUpper = true;
                ++combination;
            }
            if (islower(ch) && !includeLower) {
                includeLower = true;
                ++combination;
            }
        }

        if (combination >= 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}