// https://open.kattis.com/problems/lastfactorialdigit
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> A = {
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800
};

int main() {
    
    fast_io();
    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        cout << A.at(val) % 10 << '\n';
    }
    
    return 0;
}
