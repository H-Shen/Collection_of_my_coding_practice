#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    getline(cin, a);
    getline(cin, b);

    unordered_set<char> A(a.begin(), a.end());
    string res;
    char tmp;

    bool shiftBroken = false;
    if (A.find('+') != A.end()) {
        shiftBroken = true;
    }

    for (const auto &i : b) {
        if (shiftBroken && isupper(i)) {
            continue;
        }
        tmp = static_cast<char>(toupper(i));
        if (A.find(tmp) == A.end()) {
            res += i;
        }
    }

    if (!res.empty())
        cout << res << endl;
    else
        cout << endl;

    return 0;
}