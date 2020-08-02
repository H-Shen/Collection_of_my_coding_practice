// https://open.kattis.com/problems/knightsearch
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int STEPS = 8;
const int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
const int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
const string seq = "ICPCASIASG";

int n;
vector<vector<char> > M;
vector<pair<int, int> > origin;
bool have_ans = false;

inline
void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

inline
void dfs(int i, int j, int current_step) {
    if (have_ans) {
        return;
    }
    if (current_step == 9 && M.at(i).at(j) == 'G') {
        have_ans = true;
        return;
    }
    int next_step = current_step + 1;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && M.at(new_i).at(new_j) == seq.at(next_step)) {
            dfs(new_i, new_j, next_step);
        }
    }
}

int main() {

    fast_io();
    string s;
    cin >> n >> s;
    M.resize(n, vector<char>(n));
    auto iter = s.cbegin();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            M.at(i).at(j) = *iter;
            if (M.at(i).at(j) == 'I') {
                origin.emplace_back(make_pair(i, j));
            }
            ++iter;
        }
    }
    for (const auto &[i, j] : origin) {
        if (have_ans) {
            break;
        }
        dfs(i, j, 0);
    }
    if (have_ans) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
