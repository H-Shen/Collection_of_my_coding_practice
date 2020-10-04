#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 1005;
constexpr int STEPS = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int r, c;
array<array<char, MAXN>, MAXN> M;

namespace DequeBfs_ {
    constexpr int INF = 0x3f3f3f3f;
    array<array<int, MAXN>, MAXN> dis;

    void init() {
        for (int i = 0; i < r; ++i) {
            fill(dis.at(i).begin(), dis.at(i).begin() + c + 1, INF);
        }
    }

    void bfs(const pair<int, int> &source, const pair<int, int> &dest) {
        dis.at(source.first).at(source.second) = 0;
        deque<pair<int, int> > dq;
        dq.push_front(source);
        int new_i, new_j, w;
        while (!dq.empty()) {
            pair<int, int> u = dq.front();
            // prune
            if (u.first == dest.first && u.second == dest.second) {
                break;
            }
            dq.pop_front();
            for (int step = 0; step < STEPS; ++step) {
                new_i = u.first + dx[step];
                new_j = u.second + dy[step];
                if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
                    if (M.at(new_i).at(new_j) == M.at(u.first).at(u.second)) {
                        w = 0;
                    } else {
                        w = 1;
                    }
                    // relax
                    if (dis.at(new_i).at(new_j) > dis.at(u.first).at(u.second) + w) {
                        dis.at(new_i).at(new_j) = dis.at(u.first).at(u.second) + w;
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
}

int main() __attribute__((optimize("-O2")));
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            cin >> s;
            for (size_t j = 0; j != s.size(); ++j) {
                M.at(i).at(j) = s.at(j);
            }
        }
        DequeBfs_::init();
        DequeBfs_::bfs({0, 0}, {r - 1, c - 1});
        cout << DequeBfs_::dis.at(r - 1).at(c - 1) << '\n';
    }

    return 0;
}