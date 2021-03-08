#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ii = pair<int, int>;
using vii = vector<ii>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<vector<char> > M;
bool is_gg(int x0, int y0, const string& dir) {
    bool gg = false;
    if (dir == "^") {
        try {
            while (true) {
                --x0;
                if (M.at(x0).at(y0) == 'x') {
                    gg = true;
                    break;
                }
            }
        } catch (...) {}
    }
    else if (dir == "v") {
        try {
            while (true) {
                ++x0;
                if (M.at(x0).at(y0) == 'x') {
                    gg = true;
                    break;
                }
            }
        } catch (...) {}
    }
    else if (dir == "<") {
        try {
            while (true) {
                --y0;
                if (M.at(x0).at(y0) == 'x') {
                    gg = true;
                    break;
                }
            }
        } catch (...) {}
    }
    else if (dir == ">") {
        try {
            while (true) {
                ++y0;
                if (M.at(x0).at(y0) == 'x') {
                    gg = true;
                    break;
                }
            }
        } catch (...) {}
    }
    return gg;
}

int main() {

    fast_io();
    int n, m;
    string dir;
    cin >> n >> m >> dir;
    bool has_component = false;
    vii vv;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        M.emplace_back(s.begin(),s.end());
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'o') {
                vv.emplace_back(i, j);
            }
            if (s[j] == 'x') {
                has_component = true;
            }
        }
    }
    if (!has_component || vv.empty()) {
        cout << "OK" << '\n';
        return 0;
    }
    for (const auto &i : vv) {
        if (is_gg(i.first, i.second, dir)) {
            cout << "GG" << '\n';
            return 0;
        }
    }
    cout << "OK" << '\n';

    return 0;
}