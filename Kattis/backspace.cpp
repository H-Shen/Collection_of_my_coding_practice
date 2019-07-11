// https://open.kattis.com/problems/backspace
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    deque <char> A;
    string s;
    cin >> s;

    for (const auto & ch : s) {
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
