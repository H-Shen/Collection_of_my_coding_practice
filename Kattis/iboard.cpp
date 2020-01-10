// https://open.kattis.com/problems/iboard
//
#include <bits/stdc++.h>

using namespace std;

auto f = [](const char &ch) {
    int a = static_cast<int>(ch);
    string s;
    while (a > 0) {
        if (a % 2 == 0) {
            s.push_back('0');
        } else {
            s.push_back('1');
        }
        a /= 2;
    }
    // If s.size() < 7, append tailing zeroes to make sure s.size() == 7
    while (s.size() < 7) {
        s.push_back('0');
    }
    return s;
};

string convert(const string &s) {
    string ret;
    for (const auto &i : s) {
        ret += f(i);
    }
    return ret;
}

int main() {

    string s;
    while (getline(cin, s)) {
        bool onePressed = false;
        bool zeroPressed = false;
        s = convert(s);
        for (const auto &i : s) {
            if (i == '1') {
                onePressed = !onePressed;
            } else {
                zeroPressed = !zeroPressed;
            }
        }
        if (onePressed || zeroPressed) {
            cout << "trapped";
        } else {
            cout << "free";
        }
        cout << endl;
    }

    return 0;
}
