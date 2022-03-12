// https://open.kattis.com/problems/headguard

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

string s;

int main() {
    while (getline(cin, s)) {
        int counter = 0;
        char lastChar;
        string str;
        for (auto&i : s) {
            if (counter == 0) {
                lastChar = i;
                ++counter;
                continue;
            }
            if (i == lastChar) {
                ++counter;
            } else {
                str += to_string(counter);
                str.push_back(lastChar);
                lastChar = i;
                counter = 1;
            }
        }
        if (counter > 0) {
            str += to_string(counter);
            str.push_back(lastChar);
        }
        cout << str << '\n';
    }
    return 0;
}
