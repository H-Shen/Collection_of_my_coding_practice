// https://open.kattis.com/problems/magictrick

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    string s;
    cin >> s;
    if (unordered_set<char>(s.begin(),s.end()).size() == s.size()) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}
