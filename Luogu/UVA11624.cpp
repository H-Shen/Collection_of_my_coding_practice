#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 1005;
constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c, joe_i, joe_j;
vector<vector<char> > M;
vector<pii> fire;
vector<vector<int> > dis;
bitset<MAXN> vis_fire[MAXN];
bitset<MAXN> vis[MAXN];

// bfs on fire without people
struct Fire {
    explicit Fire(int x, int y, int t) : x(x), y(y), t(t) {}
    int x, y, t;
};
void bfs1() {
    queue<Fire> q;
    for (const auto &i : fire) {
        q.push(Fire(i.first, i.second, 0));
        dis.at(i.first).at(i.second) = 0;
        vis_fire[i.first][i.second] = true;
    }
    int new_x, new_y, new_t;
    while (!q.empty()) {
        Fire u = q.front();
        q.pop();
        for (int step = 0; step < STEPS; ++step) {
            new_x = u.x + dx[step];
            new_y = u.y + dy[step];
            new_t = u.t + 1;
            if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && M.at(new_x).at(new_y) != '#' && M.at(new_x).at(new_y) != 'F' && !vis_fire[new_x][new_y]) {
                vis_fire[new_x][new_y] = true;
                dis.at(new_x).at(new_y) = new_t;
                q.push(Fire(new_x, new_y, new_t));
            }
        }
    }
}

// bfs on people
struct Person {
    explicit Person(int x, int y, int t) : x(x), y(y), t(t) {}
    int x, y, t;
};

int bfs2(int i, int j) {
    queue<Person> q;
    q.push(Person(i, j, 0));
    vis[i][j] = true;
    int new_i, new_j, new_t;
    while (!q.empty()) {
        Person u = q.front();
        q.pop();
        for (int step = 0; step < STEPS; ++step) {
            new_i = u.x + dx[step];
            new_j = u.y + dy[step];
            new_t = u.t + 1;
            // out_of range
            if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= c) {
                return new_t;
            }
            if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && new_t < dis.at(new_i).at(new_j) && M.at(new_i).at(new_j) != 'F' && M.at(new_i).at(new_j) != '#' && !vis[new_i][new_j]) {
                vis[new_i][new_j] = true;
                q.push(Person(new_i, new_j, new_t));
            }
        }
    }
    return INF;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {

        string s;
        // input
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            cin >> s;
            M.emplace_back(s.begin(), s.end());
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (M.at(i).at(j) == 'J') {
                    joe_i = i;
                    joe_j = j;
                } else if (M.at(i).at(j) == 'F') {
                    fire.emplace_back(make_pair(i, j));
                }
            }
        }
        dis.resize(r, vector<int>(c, INF));
        bfs1();
        int result = bfs2(joe_i, joe_j);
        if (result == INF) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            cout << result << '\n';
        }
        
        // reset
        for (auto &i : vis) {
            i.reset();
        }
        for (auto &i : vis_fire) {
            i.reset();
        }
        decltype(dis)().swap(dis);
        decltype(fire)().swap(fire);
        decltype(M)().swap(M);
    }

    return 0;
}