// https://open.kattis.com/problems/findingana

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s.substr(s.find('a')) << '\n';
    return 0;
}
