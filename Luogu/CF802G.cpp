#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s = "heidi";
    deque<char> temp(s.begin(), s.end());
    cin >> s;
    for (const char &i : s) {
        if (temp.empty()) {
            break;
        }
        if (temp.front() == i) {
            temp.pop_front();
        }
    }
    if (temp.empty()) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
