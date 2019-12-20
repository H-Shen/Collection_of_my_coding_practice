// https://www.nowcoder.com/practice/3c06901112f6465d859909f2601fccbd

#include <iostream>
#include <string>

using namespace std;

inline
string repeat(const string &s, int n) {
    string result;
    for (int i = 0; i < n; ++i) {
        result += s;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s, tmp;
    cin >> s;
    int len = static_cast<int>(s.size());
    for (int i = len - 1; i > 0; --i) {
        if (len % i == 0) {
            tmp = s.substr(0, i);
            if (repeat(tmp, len / i) == s) {
                cout << tmp << endl;
                return 0;
            }
        }
    }
    cout << "false" << endl;
    return 0;
}