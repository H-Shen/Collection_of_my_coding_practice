// https://open.kattis.com/problems/softpasswords
//
#include <bits/extc++.h>

using namespace std;

inline static
string reverseCase(string s) {
    for (char &ch : s) {
        if (isupper(ch)) {
            ch = static_cast<char>(tolower(ch));
        } else if (islower(ch)) {
            ch = static_cast<char>(toupper(ch));
        }
    }
    return s;
}

int main() {

    string s, p;
    cin >> s >> p;
    // Case 1:
    if (p == s) {
        cout << "Yes" << endl;
        return 0;
    }
    // Case 2:
    for (char ch = '0'; ch <= '9'; ++ch) {
        if (s == ch + p) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    // Case 3:
    for (char ch = '0'; ch <= '9'; ++ch) {
        if (s == p + ch) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    // Case 4:
    if (s == reverseCase(p)) {
        cout << "Yes" << endl;
        return 0;
    }
    // Case 5:
    cout << "No" << endl;

    return 0;
}
