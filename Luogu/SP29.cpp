#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 101;

unordered_map<int, string> unmap;
int getHash(const string &s) {
    int ans = 0;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        ans += (i+1) * (int)s[i];
    }
    ans *= 19;
    return ans % MOD;
}

void insert(const string &s) {
    int h = getHash(s);
    if (unmap.find(h) == unmap.end()) {
        unmap[h] = s;
        return;
    }
    if (unmap[h] == s) return;
    int new_h;
    // check
    for (int j = 1; j <= 19; ++j) {
        new_h = (h + j*j + 23*j) % MOD;
        if (unmap.find(new_h) != unmap.end() && unmap[new_h] == s) {
            return;
        }
    }
    // insert
    for (int j = 1; j <= 19; ++j) {
        new_h = (h + j*j + 23*j) % MOD;
        if (unmap.find(new_h) == unmap.end()) {
            unmap[new_h] = s;
            return;
        }
    }
}

void del(const string &s) {
    int h = getHash(s);
    if (unmap.find(h) != unmap.end() && unmap[h] == s) {
        unmap.erase(h);
        return;
    }
    int new_h;
    for (int j = 1; j <= 19; ++j) {
        new_h = (h + j*j + 23*j) % MOD;
        if (unmap.find(new_h) != unmap.end() && unmap[new_h] == s) {
            unmap.erase(new_h);
            return;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        while (n--) {
            cin >> s;
            if (s[0] == 'A') {
                insert(s.substr(4));
            }
            else {
                del(s.substr(4));
            }
        }
        // output
        cout << unmap.size() << '\n';
        vector<pair<int,string> > vec(unmap.begin(),unmap.end());
        sort(vec.begin(), vec.end(), [](const auto &l, const auto &r) {
            return l.first < r.first;
        });
        for (const auto &i : vec) {
            cout << i.first << ':' << i.second << '\n';
        }
        unmap.clear();
    }

    return 0;
}
