#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int x;
    cin >> x;
    string s = to_string(x);
    string s_copy = s;
    sort(s_copy.begin(), s_copy.end());
    reverse(s_copy.begin(), s_copy.end());

    if (s == s_copy) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;

    do {
        ++cnt;
        if (cnt == 2) break;

    } while (next_permutation(s.begin(), s.end()));
    cout << s << endl;

    return 0;
}