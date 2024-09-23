// https://www.nowcoder.com/practice/1f7c1d67446e4361bf4af67c08e0b8b0
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        copy(s.rbegin(), s.rend(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }
    return 0;
}