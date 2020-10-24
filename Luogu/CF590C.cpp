#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
constexpr int COUNTRIES = 4;
const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

array<vector<vector<int> >, COUNTRIES> dis;
vector<vector<char> > M;
int n, m;

void dequeBfs(const int &country, const pii &source) {
    dis.at(country).at(source.first).at(source.second) = 0;
    deque<pii> dq;
    dq.push_front(source);
    int new_i, new_j, w;
    pii u;
    while (!dq.empty()) {
        u = dq.front();
        dq.pop_front();
        for (int step = 0; step < STEPS; ++step) {
            new_i = u.first + di[step];
            new_j = u.second + dj[step];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                M.at(new_i).at(new_j) != '#') {
                if (M.at(new_i).at(new_j) == '.') {
                    w = 1;
                } else {
                    w = 0;
                }
                if (dis.at(country).at(new_i).at(new_j) >
                    dis.at(country).at(u.first).at(u.second) + w) {
                    dis.at(country).at(new_i).at(new_j) =
                            dis.at(country).at(u.first).at(u.second) + w;
                    if (w == 0) {
                        dq.emplace_front(new_i, new_j);
                    } else {
                        dq.emplace_back(new_i, new_j);
                    }
                }
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    for (int country = 0; country < COUNTRIES; ++country) {
        dis.at(country).resize(n, vector<int>(m, INF));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) >= '1' && M.at(i).at(j) <= '3') {
                dequeBfs(M.at(i).at(j) - '0', {i, j});
            }
        }
    }
    int answer = INF;
    int current;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // check connectivity from (i, j) to three countries
            if (dis.at(1).at(i).at(j) != INF
                && dis.at(2).at(i).at(j) != INF
                && dis.at(3).at(i).at(j) != INF) {
                if (M.at(i).at(j) == '.') {
                    current = dis.at(1).at(i).at(j) + dis.at(2).at(i).at(j) +
                              dis.at(3).at(i).at(j) - 2;
                } else {
                    current = dis.at(1).at(i).at(j) + dis.at(2).at(i).at(j) +
                              dis.at(3).at(i).at(j);
                }
                answer = min(answer, current);
            }
        }
    }
    if (answer == INF) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}