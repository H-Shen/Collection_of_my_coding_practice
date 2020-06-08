#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    string s;
    cin >> n >> s;
    unordered_set<int> unset;
    for (const char &ch : s) {
        unset.insert(tolower(ch));
    }
    if (unset.size() == 26) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}