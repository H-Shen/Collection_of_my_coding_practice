// https://open.kattis.com/problems/oceancurrents
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 8;
const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vector<int> > dis;
vector<vector<char> > M;
int r, c;
void dequeBfs(const pii &source, const pii &dest) {
    // reset
    for (auto &i : dis) {
        fill(i.begin(), i.end(), INF);
    }
    dis.at(source.first).at(source.second) = 0;
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
            if (new_i >= 1 && new_i <= r && new_j >= 1 && new_j <= c) {
                if (step == M.at(u.first).at(u.second) - '0') {
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
    dis.resize(r + 5, vector<int>(c + 5));
    M.resize(r + 5, vector<char>(c + 5));
    string s;
    for (int i = 1; i <= r; ++i) {
        cin >> s;
        for (size_t j = 0; j != s.size(); ++j) {
            M.at(i).at(j + 1) = s.at(j);
        }
    }
    int q;
    cin >> q;
    pii source, dest;
    while (q--) {
        cin >> source.first >> source.second >> dest.first >> dest.second;
        dequeBfs(source, dest);
        cout << dis.at(dest.first).at(dest.second) << '\n';
    }
    return 0;
}
