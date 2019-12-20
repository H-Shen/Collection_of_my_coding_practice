// https://www.nowcoder.com/practice/14733e0bfa9b474ba7cbe0bb2e459731

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n = stol(s);
    if (n < 0) {
        s = to_string(-n);
        reverse(s.begin(), s.end());
        cout << "-" << stol(s) << endl;
    } else {
        reverse(s.begin(), s.end());
        cout << stol(s) << endl;
    }

    return 0;
}