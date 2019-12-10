// https://open.kattis.com/problems/howl
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;
    size_t length = s.size() + 1;
    cout << string(length - 3, 'A') << "HOW" << endl;

    return 0;
}
