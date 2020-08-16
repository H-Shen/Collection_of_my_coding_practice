// https://open.kattis.com/problems/flipfive
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 600;
constexpr int SIZE = 3;
constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<vector<char> > M(SIZE, vector<char>(SIZE));
array<int, MAXN> dis;
int dest;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

inline
void bfs() {
    queue<int> q;
    int source = 0;
    q.push(source);  // start from all white cells
    dis.at(source) = 0;
    while (!q.empty()) {
        int u = q.front();
        int new_u;
        q.pop();
        bitset<SIZE * SIZE> current_status(u);
        // 9 toggles
        // convert current_status to cells
        int index = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (current_status[index]) {
                    M.at(i).at(j) = '*';
                } else {
                    M.at(i).at(j) = '.';
                }
                ++index;
            }
        }
        auto M_bak(M);
        // toggle 9 cells
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                // toggle itself
                if (M.at(i).at(j) == '*') {
                    M.at(i).at(j) = '.';
                } else {
                    M.at(i).at(j) = '*';
                }
                // toggle neighbours
                for (int step = 0; step < STEPS; ++step) {
                    int new_i = i + dx[step];
                    int new_j = j + dy[step];
                    if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3) {
                        // toggle
                        if (M.at(new_i).at(new_j) == '*') {
                            M.at(new_i).at(new_j) = '.';
                        } else {
                            M.at(new_i).at(new_j) = '*';
                        }
                    }
                }
                bitset<SIZE * SIZE> new_status;
                for (int pos_i = 0; pos_i < 3; ++pos_i) {
                    for (int pos_j = 0; pos_j < 3; ++pos_j) {
                        new_status[pos_i * 3 + pos_j] =
                                M.at(pos_i).at(pos_j) == '*';
                    }
                }
                new_u = static_cast<int>(new_status.to_ulong());
                if (dis.at(new_u) == INF) {
                    q.push(new_u);
                    dis.at(new_u) = dis.at(u) + 1;
                }
                // restore
                M = M_bak;
            }
        }
    }
}

int main() {

    fast_io();
    int p, index;
    string s;
    cin >> p;
    while (p--) {
        index = 0;
        bitset<SIZE * SIZE> dest_status;
        for (int i = 0; i < 3; ++i) {
            cin >> s;
            for (int j = 0; j < 3; ++j) {
                dest_status[index++] = s.at(j) != '.';
            }
        }
        fill(dis.begin(), dis.end(), INF);
        bfs();
        dest = static_cast<int>(dest_status.to_ulong());
        cout << dis.at(dest) << '\n';
    }

    return 0;
}
