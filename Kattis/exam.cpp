// https://open.kattis.com/problems/exam
//
#include <bits/stdc++.h>

using namespace std;


int main() {

    int c;
    string s1, s2;
    cin >> c >> s1 >> s2;
    int a = 0, b = 0;
    for (size_t i = 0; i != s1.size(); ++i) {
        if (s1[i] == s2[i]) {
            ++a;
        } else {
            ++b;
        }
    }
    if (c <= a) {
        cout << c + b << endl;
    } else {
        cout << a + b - c + a << endl;
    }
    return 0;
}
