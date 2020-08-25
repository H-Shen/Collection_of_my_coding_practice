// https://open.kattis.com/problems/fontan
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int r, c;
vector<vector<char> > M;
deque<pii> temp;

int main() {

    fast_io();
    cin >> r >> c;
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (M.at(i).at(j) == 'V') {
                temp.emplace_back(i, j);
            }
        }
    }
    int cur_i, cur_j;
    while (!temp.empty()) {
        cur_i = temp.front().first;
        cur_j = temp.front().second;
        temp.pop_front();
        if (cur_i == r - 1) {
            continue;
        }
        else if (M.at(cur_i + 1).at(cur_j) == 'V') {
            continue;
        }
        else if (M.at(cur_i + 1).at(cur_j) == '.') {
            M.at(cur_i + 1).at(cur_j) = 'V';
            temp.emplace_back(cur_i + 1, cur_j);
        }
        else if (M.at(cur_i + 1).at(cur_j) == '#') {
            if (cur_j != 0 && M.at(cur_i).at(cur_j - 1) == '.') {
                M.at(cur_i).at(cur_j - 1) = 'V';
                temp.emplace_back(cur_i, cur_j - 1);
            }
            if (cur_j != c - 1 && M.at(cur_i).at(cur_j + 1) == '.') {
                M.at(cur_i).at(cur_j + 1) = 'V';
                temp.emplace_back(cur_i, cur_j + 1);
            }
        }
    }
    // output
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << M.at(i).at(j);
        }
        cout << '\n';
    }
    return 0;
}
