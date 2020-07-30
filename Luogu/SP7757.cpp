#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const regex r("[A-Za-z]+");

inline static
bool check(const string &s) {
    unordered_set<char> unset;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
        unset.insert(tolower(it->str().front()));
    }
    return unset.size() == 1;
}

int main() {

    string s;
    while (true) {
        getline(cin, s);
        if (s == "*") {
            break;
        }
        if (check(s)) {
            cout << 'Y' << '\n';
        } else {
            cout << 'N' << '\n';
        }
    }
    return 0;
}