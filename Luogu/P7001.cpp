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

constexpr int MAXN = 9;

int main() {

    fast_io();
    string s, s1;
    cin >> s;
    int n;
    cin >> n;
    vector<string> output;
    while (n--) {
        cin >> s1;
        bool haveAns = true;
        for (int i = 0; i < MAXN; ++i) {
            if (s.at(i) != s1.at(i) && s.at(i) != '*') {
                haveAns = false;
                break;
            }
        }
        if (haveAns) {
            output.emplace_back(s1);
        }
    }
    cout << output.size() << '\n';
    for (const auto &i : output) {
        cout << i << '\n';
    }

    return 0;
}