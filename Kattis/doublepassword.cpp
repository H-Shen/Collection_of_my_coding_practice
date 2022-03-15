// https://open.kattis.com/problems/doublepassword

#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 4;

int main() {
    string a,b;
    cin >> a >> b;
    int counter = 1;
    for (int i = 0; i < MAXN; ++i) {
        if (a[i] != b[i]) counter *= 2;
    }
    cout << counter << '\n';
    return 0;
}
