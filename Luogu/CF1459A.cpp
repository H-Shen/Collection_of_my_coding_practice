#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t, n, counter;
    cin >> t;
    string a, b;
    while (t--) {
        cin >> n;
        counter = 0;
        cin >> a >> b;
        for (int i = 0; i < n; ++i) {
            if (a.at(i) > b.at(i)) {
                ++counter;
            } else if (a.at(i) < b.at(i)) {
                --counter;
            }
        }
        if (counter == 0) {
            cout << "EQUAL" << '\n';
        } else if (counter > 0) {
            cout << "RED" << '\n';
        } else {
            cout << "BLUE" << '\n';
        }
    }
    return 0;
}