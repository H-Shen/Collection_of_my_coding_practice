// https://open.kattis.com/problems/showroom
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, 1, -1, 0};

vector<vector<int> > dis;
vector<vector<char> > M;
int r, c, original_i, original_j;

void dequeBfs(const pii &source, const pii &dest) {
    dis.at(source.first).at(source.second) = 1; // including the car we are moving
    deque<pii> dq;
    dq.push_front(source);
    int new_i, new_j, w;
    pii u;
    while (!dq.empty()) {
        u = dq.front();
        if (u == dest) {
            break;
        }
        dq.pop_front();
        for (int step = 0; step < STEPS; ++step) {
            new_i = u.first + di[step];
            new_j = u.second + dj[step];
            if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && M.at(new_i).at(new_j) != '#') {
                if (M.at(new_i).at(new_j) == 'D') {
                    w = 0;
                } else {
                    w = 1;
                }
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


int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> r >> c;
    r += 2;
    c += 2;
    M.resize(r, vector<char>(c));
    dis.resize(r, vector<int>(c, INF));
    for (int i = 0; i < c; ++i) {
        M.at(0).at(i) = 'D';
    }
    string s;
    for (int i = 1; i < r - 1; ++i) {
        cin >> s;
        M.at(i).at(0) = 'D';
        for (int j = 1; j < c - 1; ++j) {
            M.at(i).at(j) = s.at(j - 1);
        }
        M.at(i).at(c - 1) = 'D';
    }
    for (int i = 0; i < c; ++i) {
        M.at(r - 1).at(i) = 'D';
    }
    cin >> original_i >> original_j;
    dequeBfs({original_i, original_j}, {0, 0});
    cout << dis.at(0).at(0) << '\n';

    return 0;
}
