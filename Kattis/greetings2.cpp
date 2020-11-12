// https://open.kattis.com/problems/greetings2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin >> s;
    int e = ((int)s.size() - 2) * 2;
    cout << 'h' << string(e, 'e') << 'y' << '\n';

    return 0;
}
