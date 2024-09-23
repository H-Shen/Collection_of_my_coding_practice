// https://www.nowcoder.com/practice/ffa94d27c6534396aef38813535c279f
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t index = s.find('.');
    if (index == string::npos) {
        cout << s.back();
    } else if (index == 0) {
        cout << '0';
    } else {
        cout << s.at(index - 1);
    }
    cout << endl;
    return 0;
}