// https://www.nowcoder.com/practice/6187581174ac48278ca3bccf8d534897
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    cout << stoi(a, nullptr, 16) + stoi(b, nullptr, 8) << endl;
    return 0;
}