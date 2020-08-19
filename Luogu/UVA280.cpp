#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

constexpr int MAXN = 105;

template<size_t N>
struct TransitiveClosure {
    bitset<N> reach[N];
    void floyd_warshall(int n) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                if (reach[i][k]) {
                    reach[i] |= reach[k];    // reach[i] = reach[i] | reach[k];
                }
            }
        }
    }
    void reset() {
        for (int i = 0; i < N; ++i) {
            reach[i].reset();
        }
    }
};

const regex r("[0-9]+");
inline
vector<int> parse(const string &s) {
    vector<int> result;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
         it != end_it; ++it) {
        result.emplace_back(stoi(it->str()));
    }
    return result;
}

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(int n) {
    TransitiveClosure<MAXN> tc;
    string s;
    cin.get();
    vector<int> p;
    int length, u, counter;
    while (true) {
        getline(cin, s);
        if (s == "0") break;
        p = parse(s);
        p.pop_back();
        length = static_cast<int>(p.size());
        u = p.front();
        for (int v = 1; v < length; ++v) {
            tc.reach[u][p.at(v)] = true;
        }
    }
    tc.floyd_warshall(n);
    // query
    getline(cin, s);
    p = parse(s);
    length = static_cast<int>(p.size());
    for (int i = 1; i < length; ++i) {
        counter = 0;
        vector<int> reach_list;
        for (int j = 1; j <= n; ++j) {
            if (!tc.reach[p.at(i)][j]) {
                ++counter;
                reach_list.emplace_back(j);
            }
        }
        cout << counter;
        for (const auto &j : reach_list) {
            cout << ' ' << j;
        }
        cout << '\n';
    }
}

int main() {

    fast_io();
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        solve(n);
    }

    return 0;
}
