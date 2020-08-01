#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int D;
    cin >> D;
    vector<string> M;
    string s;
    for (int k = (D - 1) / 2; k >= 0; --k) {
        s = string(k, '*') + string(D - 2 * k, 'D') + string(k, '*');
        M.emplace_back(s);
    }
    // output
    for (const auto &i : M) cout << i << '\n';
    auto iter = M.crbegin();
    ++iter;
    while (iter != M.crend()) {
        cout << *iter << '\n';
        ++iter;
    }

    return 0;
}