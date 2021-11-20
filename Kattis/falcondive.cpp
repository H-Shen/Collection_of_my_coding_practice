// https://open.kattis.com/problems/falcondive

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int m, n;
char ch;
vector<string> f1, f2;
vector<pair<int,int>> vec1, vec2;
int r_shift, c_shift;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> m >> n >> s;
    ch = s.at(1);
    for (int i = 0; i < m; ++i) {
        cin >> s;
        f1.emplace_back(s);
    }
    for (int i = 0; i < m; ++i) {
        cin >> s;
        f2.emplace_back(s);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (f1[i][j] == ch) {
                vec1.emplace_back(i,j);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (f2[i][j] == ch) {
                vec2.emplace_back(i,j);
            }
        }
    }
    auto cmp1 = [](const pair<int,int>&l, const pair<int,int>&r) {
        return l.second < r.second;
    };
    auto cmp2 = [](const pair<int,int>&l, const pair<int,int>&r) {
        return l.first < r.first;
    };
    c_shift = max_element(vec2.begin(), vec2.end(), cmp1)->second - max_element(vec1.begin(),  vec1.end(), cmp1)->second;
    r_shift = max_element(vec2.begin(), vec2.end(), cmp2)->first - max_element(vec1.begin(),  vec1.end(), cmp2)->first;
    for (auto &[i,j] : vec2) {
        i += r_shift;
        j += c_shift;
    }
    vector<vector<char>> ans(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (f1[i][j] != ch) {
                ans[i][j] = f1[i][j];
            }
            else {
                ans[i][j] = f2[i][j];
            }
        }
    }
    for (auto &[i,j] : vec2) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            ans[i][j] = ch;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
