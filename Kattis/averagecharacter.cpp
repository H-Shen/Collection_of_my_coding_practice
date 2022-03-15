// https://open.kattis.com/problems/averagecharacter

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int sum = 0;
    for (auto&ch : s) {
        sum += (int)ch;
    }
    double avg = sum * 1.0 / (int)s.size();
    cout << (char)(int)avg << '\n';
    return 0;
}
