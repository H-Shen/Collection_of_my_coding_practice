#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    cin >> n;
    unordered_map<string, int> scores;
    string s;
    while (n--) {
        cin >> s;
        ++scores[s];
    }
    int max_val = -1;
    for (const auto &[k, v] : scores) {
        max_val = max(max_val, v);
    }
    for (const auto &[k, v] : scores) {
        if (v == max_val) {
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}