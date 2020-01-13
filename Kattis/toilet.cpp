// https://open.kattis.com/problems/toilet
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;
    bool up;

    if (s.front() == 'U') {
        up = true;
    } else {
        up = false;
    }
    // policy1
    int counter1 = 0;
    for (size_t i = 1; i != s.size(); ++i) {
        if (s.at(i) == 'U') {
            if (up) {
                counter1 += 0;
            } else {
                counter1 += 1;
            }
        } else {
            if (up) {
                counter1 += 2;
            } else {
                counter1 += 1;
            }
        }
        up = true;
    }
    cout << counter1 << endl;

    if (s.front() == 'U') {
        up = true;
    } else {
        up = false;
    }
    // policy2
    int counter2 = 0;
    for (size_t i = 1; i != s.size(); ++i) {
        if (s.at(i) == 'U') {
            if (up) {
                counter2 += 1;
            } else {
                counter2 += 2;
            }
        } else {
            if (up) {
                counter2 += 1;
            } else {
                counter2 += 0;
            }
        }
        up = false;
    }
    cout << counter2 << endl;

    if (s.front() == 'U') {
        up = true;
    } else {
        up = false;
    }
    // policy3
    int counter3 = 0;
    for (size_t i = 1; i != s.size(); ++i) {
        if (s.at(i) == 'U') {
            if (up) {
                counter3 += 0;
            } else {
                counter3 += 1;
                up = true;
            }
        } else {
            if (up) {
                counter3 += 1;
                up = false;
            } else {
                counter3 += 0;
            }
        }
    }
    cout << counter3 << endl;

    return 0;
}
