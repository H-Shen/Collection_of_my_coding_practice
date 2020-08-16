// https://open.kattis.com/problems/safe
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 265000;
constexpr int BASE = 4;
constexpr int SIDE = 3;
constexpr int INF = 0x3f3f3f3f;

constexpr int STEPS = 9;
const int dx[] = {0, 0, 0, 0, 0, 1, 2, -1, -2};
const int dy[] = {0, 1, 2, -1, -2, 0, 0, 0, 0};

array<int, MAXN> dis;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

inline
vector<vector<int> > convert(int number) {
    vector<vector<int> > M(SIDE, vector<int>(SIDE));
    string s;
    while (number > 0) {
        s.push_back(number % BASE + '0');
        number /= BASE;
    }
    while (s.size() < 9) {
        s.push_back('0');
    }
    reverse(s.begin(), s.end());
    int index = 0;
    for (int i = 0; i < SIDE; ++i) {
        for (int j = 0; j < SIDE; ++j) {
            M.at(i).at(j) = s.at(index++) - '0';
        }
    }
    return M;
}

inline
int convert(const vector<vector<int> > &M) {
    string s;
    for (int i = 0; i < SIDE; ++i) {
        for (int j = 0; j < SIDE; ++j) {
            s.push_back(M.at(i).at(j) + '0');
        }
    }
    return stoi(s, nullptr, BASE);
}

inline
void bfs(int u) {
    queue<int> q;
    q.push(u);
    fill(dis.begin(), dis.end(), INF);
    dis.at(u) = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        auto vec = convert(current);
        auto vec_bak(vec);
        int new_i, new_j;
        for (int i = 0; i < SIDE; ++i) {
            for (int j = 0; j < SIDE; ++j) {
                // all possible steps
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < SIDE && new_j >= 0 && new_j < SIDE) {
                        vec.at(new_i).at(new_j) = (vec.at(new_i).at(new_j) + 1) % BASE;
                    }
                }
                int next = convert(vec);
                if (dis.at(next) == INF) {
                    q.push(next);
                    dis.at(next) = dis.at(current) + 1;
                }
                // restore
                vec = vec_bak;
            }
        }
    }
}

int main() {

    fast_io();
    string s;
    int val;
    for (int i = 0; i < SIDE; ++i) {
        for (int j = 0; j < SIDE; ++j) {
            cin >> val;
            s.push_back(val + '0');
        }
    }
    bfs(stoi(s, nullptr, BASE));
    if (dis.at(0) == INF) {
        cout << -1;
    } else {
        cout << dis.at(0);
    }
    cout << '\n';
    return 0;
}
