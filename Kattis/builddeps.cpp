// https://open.kattis.com/problems/builddeps
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline static
vector<string> split_by_char(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

// A collection of containers and procedures that implements the topological
// sort using DFS
namespace ToposortByDfs {
    // adjacency list of the graph
    gp_hash_table<int, vector<int>, custom_hash> G;
    vector<bool> vis;
    vector<int> ans;
    void dfs(int u) {
        vis[u] = true;
        for (const auto &v : G[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
        ans.emplace_back(u);
    }
}

unordered_map<string, int> name2index;
vector<string> index2name;
int counter = 0;
int n;

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int rules;
    string s;
    string name;
    vector<string> p;
    cin >> rules;
    cin.get();
    while (rules--) {
        getline(cin, s);
        p = split_by_char(s, ' ');
        if (p.size() == 1) {
            name = p.front();
            name.pop_back();
            if (name2index.find(name) == name2index.end()) {
                name2index[name] = counter;
                index2name.emplace_back(name);
                ++counter;
            }
        } else {
            p.front().pop_back();
            if (name2index.find(p.front()) == name2index.end()) {
                name2index[p.front()] = counter;
                index2name.emplace_back(p.front());
                ++counter;
            }
            for (size_t i = 1; i != p.size(); ++i) {
                if (name2index.find(p.at(i)) == name2index.end()) {
                    name2index[p.at(i)] = counter;
                    index2name.emplace_back(p.at(i));
                    ++counter;
                }
                ToposortByDfs::G[name2index[p.at(i)]].emplace_back(name2index[p.front()]);
            }
        }
    }

    n = counter;
    string search;
    cin >> search;
    vector<bool>().swap(ToposortByDfs::vis);
    vector<int>().swap(ToposortByDfs::ans);
    ToposortByDfs::vis.resize(n, false);
    ToposortByDfs::dfs(name2index[search]);
    reverse(ToposortByDfs::ans.begin(), ToposortByDfs::ans.end());
    for (const auto &i : ToposortByDfs::ans) {
        cout << index2name.at(i) << '\n';
    }

    return 0;
}
