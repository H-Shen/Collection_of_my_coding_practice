// https://open.kattis.com/problems/breakingbad
// bipartite check
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll [[maybe_unused]] = long long;
using pii [[maybe_unused]] = pair<int, int>;

enum class COLOR {
    WHITE, GREEN, RED
};

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n, m;
unordered_map<string, int> name2id;
vector<string> id2name;
vector<vector<int> > adj;
int global_id = 1;
vector<COLOR> color;

inline
bool dfs(const int &u, const COLOR &c) {
    color.at(u) = c;
    for (const auto &v : adj.at(u)) {
        if (color.at(v) == c) {
            return false;
        }
        if (color.at(v) == COLOR::WHITE) {
            if (c == COLOR::GREEN && !dfs(v, COLOR::RED)) {
                return false;
            }
            if (c == COLOR::RED && !dfs(v, COLOR::GREEN)) {
                return false;
            }
        }
    }
    return true;
}

inline
bool check() {
    for (int i = 1; i <= n; ++i) {
        if (color.at(i) == COLOR::WHITE) {
            if (!dfs(i, COLOR::GREEN)) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    fast_io();
    cin >> n;
    adj.resize(n + 5);
    color.resize(n + 5, COLOR::WHITE);
    id2name.resize(n + 5);
    string name;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        name2id[name] = global_id;
        id2name.at(global_id) = name;
        ++global_id;
    }
    cin >> m;
    string u_name, v_name;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u_name >> v_name;
        u = name2id[u_name];
        v = name2id[v_name];
        adj.at(u).emplace_back(v);
        adj.at(v).emplace_back(u);
    }
    if (check()) {
        vector<string> A;
        vector<string> B;
        for (int i = 1; i <= n; ++i) {
            if (color.at(i) == COLOR::RED) {
                A.emplace_back(id2name.at(i));
            } else {
                B.emplace_back(id2name.at(i));
            }
        }
        bool first_case;
        first_case = true;
        for (const auto &i : A) {
            if (first_case) {
                first_case = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
        cout << '\n';
        first_case = true;
        for (const auto &i : B) {
            if (first_case) {
                first_case = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
        cout << '\n';
    } else {
        cout << "impossible" << '\n';
    }
    return 0;
}
