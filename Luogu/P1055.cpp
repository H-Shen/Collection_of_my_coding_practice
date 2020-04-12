#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

string solve(string s) {
    string str;
    for (const char &i : s) {
        if (i != '-') {
            str.push_back(i);
        }
    }
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (str.at(i) - '0') * (i + 1);
    }
    sum %= 11;
    if (sum == 10) {
        if (str.at(9) == 'X') {
            return "Right";
        } else {
            s.back() = 'X';
            return s;
        }
    }
    
    if (sum + '0' == str.at(9)) {
        s = "Right";
    } else {
        s.back() = sum + '0';
    }
    return s;
}

int main() {

    string s;
    cin >> s;
    cout << solve(s) << '\n';

    return 0;
}
