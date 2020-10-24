// https://open.kattis.com/problems/jailbreak
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
constexpr int CRIMINALS = 3;
const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

array<vector<vector<int> >, CRIMINALS> dis;
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
                M.at(new_i).at(new_j) != '*') {
                if (M.at(new_i).at(new_j) == '#') {
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
    string s;
    int t;
    int counter_of_criminals;
    int answer;
    int current;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        // add a boundary
        n += 2;
        m += 2;
        M.resize(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            M.at(0).at(i) = '.';
        }
        M.at(0).at(0) = '$';
        for (int i = 1; i < n - 1; ++i) {
            cin >> s;
            M.at(i).at(0) = '.';
            for (int j = 1; j < m - 1; ++j) {
                M.at(i).at(j) = s.at(j - 1);
            }
            M.at(i).at(m - 1) = '.';
        }
        for (int i = 0; i < m; ++i) {
            M.at(n - 1).at(i) = '.';
        }
        for (auto &i : M) {
            for (auto &j : i) {
                if (j == '$') {
                    j = counter_of_criminals + '0';
                    ++counter_of_criminals;
                }
            }
        }
        // init 'dis'
        for (int criminal = 0; criminal < CRIMINALS; ++criminal) {
            dis.at(criminal).resize(n, vector<int>(m, INF));
        }
        // start 01-bfs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M.at(i).at(j) >= '0' && M.at(i).at(j) <= '2') {
                    dequeBfs(M.at(i).at(j) - '0', {i, j});
                }
            }
        }
        // output
        answer = INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // check connectivity from (i, j) to three countries
                if (dis.at(0).at(i).at(j) != INF
                    && dis.at(1).at(i).at(j) != INF
                    && dis.at(2).at(i).at(j) != INF) {
                    if (M.at(i).at(j) == '#') {
                        current = dis.at(0).at(i).at(j) + dis.at(1).at(i).at(j) +
                                  dis.at(2).at(i).at(j) - 2;
                    } else {
                        current = dis.at(0).at(i).at(j) + dis.at(1).at(i).at(j) +
                                  dis.at(2).at(i).at(j);
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
        // clear
        decltype(M)().swap(M);
        for (int criminal = 0; criminal < CRIMINALS; ++criminal) {
           vector<vector<int> >().swap(dis.at(criminal));
        }
        counter_of_criminals = 0;
    }
    return 0;
}
