// https://open.kattis.com/problems/thegrandadventure

#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    int n;
    cin >> n;

    while (n--) {

        stack<char> a;
        bool haveAns = true;
        cin >> s;

        for (const auto &ch : s) {
            if (ch == '.') {
                continue;
            }
            if (ch == '$' || ch == '*' || ch == '|') {
                a.push(ch);
            } else if (ch == 't') {
                if (a.empty() || a.top() != '|') {
                    haveAns = false;
                    break;
                } else {
                    a.pop();
                }
            } else if (ch == 'b') {
                if (a.empty() || a.top() != '$') {
                    haveAns = false;
                    break;
                } else {
                    a.pop();
                }
            } else if (ch == 'j') {
                if (a.empty() || a.top() != '*') {
                    haveAns = false;
                    break;
                } else {
                    a.pop();
                }
            }
        }

        if (haveAns && a.empty()) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}
