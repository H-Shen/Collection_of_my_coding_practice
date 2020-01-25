// https://open.kattis.com/problems/delimitersoup
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    cin.get();
    getline(cin, s);
    stack<char> A;
    char ch;

    for (size_t i = 0; i != s.size(); ++i) {
        if (s.at(i) == '[' || s.at(i) == '{' || s.at(i) == '(') {
            A.push(s.at(i));
        } else if (s.at(i) == ']' || s.at(i) == '}' || s.at(i) == ')') {
            if (A.empty()) {
                cout << s.at(i) << ' ' << i << endl;
                return 0;
            } else {
                ch = A.top();
                if (s.at(i) == ']' && ch != '[') {
                    cout << s.at(i) << ' ' << i << endl;
                    return 0;
                }
                if (s.at(i) == ')' && ch != '(') {
                    cout << s.at(i) << ' ' << i << endl;
                    return 0;
                }
                if (s.at(i) == '}' && ch != '{') {
                    cout << s.at(i) << ' ' << i << endl;
                    return 0;
                }
                A.pop();
            }
        }
    }

    cout << "ok so far" << endl;

    return 0;
}
