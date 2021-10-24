// https://open.kattis.com/problems/victorythroughsynergy

#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 10;
struct Node {
    int country, league, team;
};
int c, u, v;
unordered_map<string,int> country2id, league2id, team2id;
vector<int> adj[MAXN];
Node formation[MAXN];
int id[MAXN];
int deg[MAXN];

inline
int getSynergy(Node& l, Node& r) {
    if (l.country != r.country) {
        if (l.team == r.team) {
            return 2;
        }
        else if (l.league == r.league) {
            return 1;
        }
        return 0;
    }
    else {
        if (l.team == r.team) {
            return 3;
        }
        else if (l.league == r.league) {
            return 2;
        }
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c;
    while (c--) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        ++deg[u];
        ++deg[v];
    }
    string name, country, league, team;
    Node node;
    for (auto & i : formation) {
        cin >> name >> country >> league >> team;
        if (country2id.find(country) == country2id.end()) {
            country2id[country] = (int)country2id.size();
        }
        node.country = country2id[country];
        if (league2id.find(league) == league2id.end()) {
            league2id[league] = (int)league2id.size();
        }
        node.league = league2id[league];
        if (team2id.find(team) == team2id.end()) {
            team2id[team] = (int)team2id.size();
        }
        node.team = team2id[team];
        i = node;
    }
    for (int i = 0; i < MAXN; ++i) {
        id[i] = i;
    }
    int synergy;
    bool haveAns;
    do {
        haveAns = true;
        for (int i = 0; i < MAXN; ++i) {
            synergy = 0;
            for (const auto &j : adj[i]) {
                synergy += getSynergy(formation[id[i]], formation[id[j]]);
            }
            if (synergy < deg[i]) {
                haveAns = false;
                break;
            }
        }
        if (haveAns) {
            cout << "yes" << '\n';
            return 0;
        }
    } while (next_permutation(id, id + MAXN));
    cout << "no" << '\n';
    return 0;
}
