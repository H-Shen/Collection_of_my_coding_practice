// https://open.kattis.com/problems/backspace
#include<bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    deque<char> A;
    string s;
    cin >> s;

    for (const auto &ch : s) {
        if (ch == '<') {
            A.pop_back();
        } else {
            A.push_back(ch);
        }
    }
    if (!A.empty()) {
        for (const auto &it : A) {
            cout << it;
        }
        cout << endl;
    }

    return 0;
}
