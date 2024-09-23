// https://www.nowcoder.com/practice/4e089ee8966a4ed4b306f64e68d45264
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
    }
    return 0;
}