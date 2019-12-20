// https://www.nowcoder.com/practice/0c630b57e3d144379508d63d8eb65854

#include <bits/stdc++.h>

using namespace std;

inline static
bool isAnInteger(const string &s) {
    if (!isdigit(s.front()) && s.front() != '-') {
        return false;
    }
    if (s.front() == '0' && s.size() > 1) {
        return false;
    }
    for (size_t i = 0; i != s.size(); ++i) {
        if (i != 0 && !isdigit(s.at(i))) {
            return false;
        }
    }
    try {
        int val = stoi(s);
    } catch (...) {
        return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    if (isAnInteger(s)) {
        cout << stoi(s) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}