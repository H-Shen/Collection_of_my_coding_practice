#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    unordered_set<char> A(b.begin(), b.end());
    string res;
    unordered_set<char> resSet;
    char tmp;

    for (auto &i : a) {
        if (A.find(i) == A.end()) {
            tmp = toupper(i);
            if (resSet.find(tmp) == resSet.end()) {
                res = res + tmp;
                resSet.insert(tmp);
            }
        }
    }

    cout << res << endl;
    return 0;
}