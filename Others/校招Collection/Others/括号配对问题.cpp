// https://www.nowcoder.com/practice/57260c08eaa44feababd05b328b897d7

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> S;
    for (const auto &ch : s) {
        if (ch == '[' || ch == '(') {
            S.push(ch);
        } else if (ch == ']') {
            if (S.empty() || S.top() != '[') {
                cout << "false" << endl;
                return 0;
            } else {
                S.pop();
            }
        } else if (ch == ')') {
            if (S.empty() || S.top() != '(') {
                cout << "false" << endl;
                return 0;
            } else {
                S.pop();
            }
        }
    }
    if (S.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}