#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string name;
    int before;
    int after;
    cin >> n;
    int counter = 0;
    while (n--) {
        cin >> name >> before >> after;
        if (before >= 2400 && after > before) {
            ++counter;
        }
    }
    if (counter > 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}