#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

const string str = "CAMBRIDGE";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    getline(cin, s);
    for (auto &i : s) {
        if (str.find(i) == string::npos) {
            cout << i;
        }
    }
    cout << '\n';
    return 0;
}