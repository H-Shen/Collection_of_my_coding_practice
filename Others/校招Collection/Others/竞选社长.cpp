// https://www.nowcoder.com/practice/45a30e3ef51040ed8a7674984d6d1553
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    int a = count(s.begin(), s.end(), 'A');
    int b = count(s.begin(), s.end(), 'B');
    if (a > b) {
        cout << 'A';
    } else if (a == b) {
        cout << 'E';
    } else {
        cout << 'B';
    }
    cout << endl;

    return 0;
}