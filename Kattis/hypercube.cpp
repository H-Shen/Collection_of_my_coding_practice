// https://open.kattis.com/problems/hypercube
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

unordered_map<string, ll> unmap;

ll solve(const string& s) {
    deque<char> d(s.begin(), s.end());
    while (d.size() > 1 && d.front() == '0') {
        d.pop_front();
    }
    string s_new(d.begin(), d.end());
    if (unmap.find(s_new) != unmap.end()) return unmap[s_new];
    ll temp = (1LL<<s_new.size()) - solve(s_new.substr(1)) - 1LL;
    unmap[s_new] = temp;
    return temp;
}

int main() {

    unmap["0"] = 0;
    unmap["1"] = 1;
    string a, b;
    int n;
    cin >> n >> a >> b;
    ll answer = max(solve(b) - solve(a) - 1LL, 0LL);
    cout << answer << '\n';

    return 0;
}
