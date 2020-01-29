#include <bits/stdc++.h>

using namespace std;


int main() {

    int a, b;
    string s, s_a, s_b;
    cin >> s;

    auto it = s.begin();
    while (*it != ':') {
        s_a = s_a + (*it);
        ++it;
    }
    ++it;
    while (it != s.end()) {
        s_b = s_b + (*it);
        ++it;
    }

    a = stoi(s_a);
    b = stoi(s_b);

    if (a >= 0 && a <= 12) {
        cout << "Only " << s << ".  Too early to Dang." << endl;
    } else {
        int cnt = a - 12;
        if (b > 0) {
            ++cnt;
        }
        while (cnt--) {
            cout << "Dang";
        }
        cout << endl;
    }

    return 0;
}