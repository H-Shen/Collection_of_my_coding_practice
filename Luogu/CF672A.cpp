#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        s += to_string(i);
    }
    cout << s.at(n - 1) << '\n';

    return 0;
}
