#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    string s;
    cin >> s;
    try {
        ll temp = stoll(s);
        if (temp >= -128 && temp <= 127) {
            cout << "byte" << '\n';
        } else if (temp >= -32768 && temp <= 32767) {
            cout << "short" << '\n';
        } else if (temp >= -2147483648 && temp <= 2147483647) {
            cout << "int" << '\n';
        } else {
            cout << "long" << '\n';
        }
    } catch (...) {
        cout << "BigInteger" << '\n';
    }

    return 0;
}
