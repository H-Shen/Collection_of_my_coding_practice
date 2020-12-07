#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

int main() {

    string s;
    cin >> s;
    string a = s.substr(1, 2);
    string b = s.substr(3, 2);
    string c = s.substr(5);
    printf("#%02X%02X%02X", 255 - stoi(a, nullptr, 16),
           255 - stoi(b, nullptr, 16), 255 - stoi(c, nullptr, 16));

    return 0;
}