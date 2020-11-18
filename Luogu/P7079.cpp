#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 26;
bitset<MAXN> vis;

int main() {

    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        vis[s.front() - 'A'] = true;
    }
    int counter = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (!vis[i]) break;
        ++counter;
    }
    cout << counter << '\n';

    return 0;
}