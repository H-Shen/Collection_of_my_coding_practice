#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const regex r("[0-9]+");

int main() {

    fast_io();
    string s;
    cin >> s;
    unordered_set<string> unset;
    for (sregex_iterator a(s.begin(), s.end(), r), e; a != e; ++a) {
        unset.insert(a->str());
    }
    cout << unset.size() << '\n';
    return 0;
}