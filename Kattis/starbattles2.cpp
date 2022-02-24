// https://open.kattis.com/problems/starbattles2

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using ll = long long;

const int MAXN = 10;
vector<vector<char> > M;
int region_stats[MAXN]{};
int col_stats[MAXN]{};
bitset<MAXN+5> vis[MAXN+5];

void dfs(int i) {
    if (i == MAXN) {
        for (int i_ = 0; i_ < MAXN; ++i_) {
            for (int j = 0; j < MAXN; ++j) {
                if (vis[i_][j]) cout << '*';
                else cout << '.';
            }
            cout << '\n';
        }
        exit(0);
    }
    if (i == 0) {
        for (int j1 = 0; j1 < MAXN-1; ++j1) {
            for (int j2 = j1+1; j2 < MAXN; ++j2) {
                if (j2-j1 > 1) {
                    if (M[i][j1] == M[i][j2] && region_stats[M[i][j1] - '0'] == 0) {
                        if (j1 == 0 && j2 < MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                region_stats[M[i][j1] - '0'] += 2;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                                region_stats[M[i][j1] - '0'] -= 2;
                            }
                        }
                        else if (j1 > 0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 ) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                region_stats[M[i][j1] - '0'] += 2;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                                region_stats[M[i][j1] - '0'] -= 2;
                            }
                        }
                        else if (j1==0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 ) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                region_stats[M[i][j1] - '0'] += 2;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                                region_stats[M[i][j1] - '0'] -= 2;
                            }
                        }
                        else {
                            if (col_stats[j1]<2 && col_stats[j2]<2 ) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                region_stats[M[i][j1] - '0'] += 2;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                                region_stats[M[i][j1] - '0'] -= 2;
                            }
                        }
                    }
                    else if (M[i][j1] != M[i][j2] && region_stats[M[i][j1] - '0'] < 2 && region_stats[M[i][j2] - '0'] < 2) {
                        if (j1 == 0 && j2 < MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 ) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else if (j1 > 0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 ) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else if (j1 == 0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 ) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else {
                            if (col_stats[j1]<2 && col_stats[j2]<2 ) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        for (int j1 = 0; j1 < MAXN-1; ++j1) {
            for (int j2 = j1+1; j2 < MAXN; ++j2) {
                if (j2-j1 > 1) {
                    if (M[i][j1] == M[i][j2] && region_stats[M[i][j1] - '0'] == 0) {
                        if (j1 == 0 && j2 < MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1] && !vis[i-1][j2+1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0'] += 2;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0'] -= 2;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else if (j1 > 0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1-1] && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0'] += 2;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0'] -= 2;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else if (j1==0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0'] += 2;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0'] -= 2;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1-1] && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1] && !vis[i-1][j2+1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0'] += 2;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0'] -= 2;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                    }
                    else if (M[i][j1] != M[i][j2] && region_stats[M[i][j1] - '0'] < 2 && region_stats[M[i][j2] - '0'] < 2) {
                        if (j1 == 0 && j2 < MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1] && !vis[i-1][j2+1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else if (j1 > 0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1-1] && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else if (j1 == 0 && j2 == MAXN - 1) {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                        else {
                            if (col_stats[j1]<2 && col_stats[j2]<2 && !vis[i-1][j1-1] && !vis[i-1][j1] && !vis[i-1][j1+1] && !vis[i-1][j2] && !vis[i-1][j2-1] && !vis[i-1][j2+1]) {
                                col_stats[j1]++;
                                col_stats[j2]++;
                                region_stats[M[i][j1] - '0']++;
                                region_stats[M[i][j2] - '0']++;
                                vis[i][j1] = true;
                                vis[i][j2] = true;
                                dfs(i+1);
                                col_stats[j1]--;
                                col_stats[j2]--;
                                region_stats[M[i][j1] - '0']--;
                                region_stats[M[i][j2] - '0']--;
                                vis[i][j1] = false;
                                vis[i][j2] = false;
                            }
                        }
                    }
                }
            }
        }
    }

}

int main() {
    string s;
    for (int i = 0; i < MAXN; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    dfs(0);
    return 0;
}
