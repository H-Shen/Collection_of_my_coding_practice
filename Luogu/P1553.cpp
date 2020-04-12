#include <bits/extc++.h>

using namespace std;

string solve(string s) {
    if (s == "0") {
        return s;
    }
    reverse(s.begin(), s.end());
    while (s.size() > 1 && s.front() == '0') {
        s = s.substr(1);
    }
    return s;
}

int main() {

    string s;
    cin >> s;
    int length = static_cast<int>(s.size());
    if (count(s.begin(), s.end(), '.') > 0) {
        string a;
        string b;
        int i = 0;
        for (;; ++i) {
            if (s.at(i) == '.') {
                break;
            }
            a.push_back(s.at(i));
        }
        ++i;
        for (; i < length; ++i) {
            if (s.at(i) == '.') {
                break;
            }
            b.push_back(s.at(i));
        }
        b = solve(b);
        while (b.size() > 1 && b.back() == '0') {
            b.pop_back();
        }
        cout << solve(a) << '.' << b;
    } else if (count(s.begin(), s.end(), '%') > 0) {
        s.pop_back();
        cout << solve(s) << '%';
    } else if (count(s.begin(), s.end(), '/') > 0) {
        string a;
        string b;
        int i = 0;
        for (;; ++i) {
            if (s.at(i) == '/') {
                break;
            }
            a.push_back(s.at(i));
        }
        ++i;
        for (; i < length; ++i) {
            if (s.at(i) == '/') {
                break;
            }
            b.push_back(s.at(i));
        }
        cout << solve(a) << '/' << solve(b);
    } else {
        cout << solve(s);
    }
    cout << '\n';

    return 0;
}
