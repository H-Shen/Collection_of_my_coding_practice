#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ll a;
    cin >> a;
    stringstream ss;
    ss << hex << a;
    string s(ss.str());
    int counter = 0;
    for (auto &i : s) {
        i = toupper(i);
        if (i == '0' || i == '4' || i == '6' || i == '9' || i == 'A' || i == 'D') {
            ++counter;
        } else if (i == '8' || i == 'B') {
            counter += 2;
        }
    }
    cout << counter << '\n';
    return 0;
}
