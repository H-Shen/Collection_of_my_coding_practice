// https://open.kattis.com/problems/erdosnumbers
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
inline string ERDOS_NAME = "PAUL_ERDOS";
inline regex r("[A-Za-z\\-_]+");

inline static
vector<string> split(const string &s) {
    vector<string> A;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
        A.emplace_back(it->str());
    }
    return A;
}

vector<string> names;
vector<int> query;
unordered_map<string, int> name2index;
unordered_map<int, int> erdosNumber;
unordered_map<int, unordered_set<int> > E;
vector<bool> vis;
int counter = 0;

void bfs(int id) {
    queue<int> q;
    q.push(id);
    vis.at(id) = true;
    while (!q.empty()) {
        int current_id = q.front();
        q.pop();
        for (const int &adj_id : E[current_id]) {
            if (!vis.at(adj_id)) {
                q.push(adj_id);
                erdosNumber[adj_id] = erdosNumber[current_id] + 1;
                vis.at(adj_id) = true;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    vector<string> p;
    while (getline(cin, s)) {
        p = split(s);
        for (const auto &i : p) {
            if (name2index.find(i) == name2index.end()) {
                name2index[i] = counter;
                names.emplace_back(i);
                ++counter;
            }
        }
        if (p.size() > 1) {
            int author = name2index[p.front()];
            for (size_t i = 1; i != p.size(); ++i) {
                if (name2index[p.at(i)] != author) {
                    E[author].insert(name2index[p.at(i)]);
                    E[name2index[p.at(i)]].insert(author);
                }
            }
        }
        query.emplace_back(name2index[p.front()]);
    }
    vis.resize(counter, false);
    erdosNumber[name2index[ERDOS_NAME]] = 0;
    bfs(name2index[ERDOS_NAME]);
    for (const auto &i : query) {
        cout << names[i] << ' ';
        if (erdosNumber.find(i) == erdosNumber.end()) {
            cout << "no-connection" << '\n';
        } else {
            cout << erdosNumber[i] << '\n';
        }
    }

    return 0;
}
