// https://open.kattis.com/problems/drunkvigenere
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    string a;
    string key_str;
    cin >> a >> key_str;
    vector<int> key(key_str.size());
    bool flag = true;
    for (size_t i = 0; i != key_str.size(); ++i) {
        key.at(i) = static_cast<int>(key_str.at(i) - 'A');
        if (flag) {
            key.at(i) *= -1;
            flag = false;
        } else {
            flag = true;
        }
    }
    for (size_t i = 0; i != a.size(); ++i) {
        int dist = key.at(i);
        while (abs(dist) != 0) {
            if (dist > 0) {
                ++a.at(i);
                --dist;
            } else {
                --a.at(i);
                ++dist;
            }
            if (a.at(i) > 'Z') {
                a.at(i) = 'A';
            }
            else if (a.at(i) < 'A') {
                a.at(i) = 'Z';
            }
        }
    }
    cout << a << '\n';

    return 0;
}
