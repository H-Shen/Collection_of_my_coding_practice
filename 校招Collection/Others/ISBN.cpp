// https://ac.nowcoder.com/acm/contest/236/D

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    char lastDigit = '\0';
    char correctLastDigit;
    string otherDigits;
    for (size_t i = 0; i != s.size(); ++i) {
        if (i == s.size() - 1) {
            lastDigit = s[i];
        } else if (s[i] != '-') {
            otherDigits.push_back(s[i]);
        }
    }
    int sum = 0;
    for (size_t i = 0; i != otherDigits.size(); ++i) {
        sum += static_cast<int>(otherDigits[i] - '0') * static_cast<int>(i + 1);
    }
    sum %= 11;
    if (sum == 10) {
        correctLastDigit = 'X';
    } else {
        correctLastDigit = static_cast<char>('0' + sum);
    }

    // output
    if (correctLastDigit == lastDigit)  {
        cout << "Right" << endl;
    } else {
        cout << s.substr(0, s.size() - 1) << correctLastDigit << endl;
    }

    return 0;
}