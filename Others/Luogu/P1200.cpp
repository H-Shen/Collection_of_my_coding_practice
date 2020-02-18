#include <bits/extc++.h>

using namespace std;
using ll = long long;

ll convert(const string &s) {
    ll sum = 1;
    for (const auto &i : s) {
        sum *= static_cast<ll>(i - 'A' + 1);
    }
    return sum % 47;
}

int main() {

    string a, b;
    cin >> a >> b;
    if (convert(b) == convert(a)) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }

    return 0;
}