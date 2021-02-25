// https://open.kattis.com/problems/island

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

namespace DSU {
    vector<int> father, Size;
    int number_of_sets;
    void reset() {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        number_of_sets = 0;
    }
    void init(int n) {
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        number_of_sets = n;
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
        --number_of_sets;
    }
}

vector<pair<int, int> > f(const string &s) {
    static const regex r ("XB{1,}X");
    size_t skip = 0;
    smatch smatch1;
    vector<pair<int, int> > vec;
    while (true) {
        if (regex_search(s.begin() + skip, s.end(), smatch1, r)) {
            vec.emplace_back(smatch1.position() + 1 + skip, smatch1.position() + smatch1.length() + skip - 2);
            skip += smatch1.position() + smatch1.length() - 1;
            if (skip >= s.size()) {
                break;
            }
        } else {
            break;
        }
    }
    return vec;
}

vector<pair<int, int> > g(const string &s) {
    static const regex r ("XB{1,}X");
    size_t skip = 0;
    smatch smatch1;
    vector<pair<int, int> > vec;
    while (true) {
        if (regex_search(s.begin() + skip, s.end(), smatch1, r)) {
            vec.emplace_back(smatch1.position() + skip, smatch1.position() + smatch1.length() + skip - 1);
            skip += smatch1.position() + smatch1.length() - 1;
            if (skip >= s.size()) {
                break;
            }
        } else {
            break;
        }
    }
    return vec;
}

int map_counter = 1;
vector<string> M;
int n, m;
int islands, bridges, buses;

void solve() {
    if (M.empty()) return;
    n = (int)M.size();
    m = (int)M.front().size();
    vector<pair<int, int> > pos_of_x;
    // islands
    DSU::reset();
    DSU::init(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == 'X') {
                M.at(i).at(j) = '#';
                pos_of_x.emplace_back(i, j);
            }
        }
    }
    int new_i, new_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == '#') {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(new_i).at(new_j) == '#') {
                        DSU::merge(i*m+j, new_i*m+new_j);
                    }
                }
            }
        }
    }
    unordered_set<int> groups;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == '#') {
                groups.insert(DSU::find(i*m+j));
            }
        }
    }
    islands = (int)groups.size();

    for (const auto &[i, j] : pos_of_x) {
        M.at(i).at(j) = 'X';
    }
    // bridges
    DSU::reset();
    DSU::init(n * m);
    // rows
    for (int i = 0; i < n; ++i) {
        auto p = f(M.at(i));
        for (const auto &[j0, j1] : p) {
            if (j1 > j0) {
                for (int c = j0; c <= j1 - 1; ++c) {
                    DSU::merge(i * m + c, i * m + c + 1);
                }
            }
        }
    }
    // columns
    for (int i = 0; i < m; ++i) {
        string str;
        for (int j = 0; j < n; ++j) {
            str += M.at(j).at(i);
        }
        auto p = f(str);
        for (const auto &[j0, j1] : p) {
            if (j1 > j0) {
                for (int c = j0; c <= j1 - 1; ++c) {
                    DSU::merge(c * m + i, (c + 1) * m + i);
                }
            }
        }
    }
    groups.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == 'B') {
                groups.insert(DSU::find(i*m+j));
            }
        }
    }
    bridges = (int)groups.size();
    // buses
    DSU::reset();
    DSU::init(n*m);
    // rows
    for (int i = 0; i < n; ++i) {
        auto p = g(M.at(i));
        for (const auto &[j0, j1] : p) {
            if (j1 > j0) {
                for (int c = j0; c <= j1 - 1; ++c) {
                    DSU::merge(i * m + c, i * m + c + 1);
                }
            }
        }
    }
    // columns
    for (int i = 0; i < m; ++i) {
        string str;
        for (int j = 0; j < n; ++j) {
            str += M.at(j).at(i);
        }
        auto p = g(str);
        for (const auto &[j0, j1] : p) {
            if (j1 > j0) {
                for (int c = j0; c <= j1 - 1; ++c) {
                    DSU::merge(c * m + i, (c + 1) * m + i);
                }
            }
        }
    }
    for (const auto &[i, j] : pos_of_x) {
        M.at(i).at(j) = '#';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == '#') {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(new_i).at(new_j) == '#') {
                        DSU::merge(i*m+j, new_i*m+new_j);
                    }
                }
            }
        }
    }
    groups.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == '#') {
                groups.insert(DSU::find(i*m+j));
            }
        }
    }
    buses = (int)groups.size();
}

void print() {
    if (map_counter > 1) {
        cout << '\n';
    }
    cout << "Map " << map_counter << '\n';
    cout << "islands: " << islands << '\n';
    cout << "bridges: " << bridges << '\n';
    cout << "buses needed: " << buses << '\n';
    ++map_counter;
}

void reset() {
    vector<string>().swap(M);
    islands = 0;
    bridges = 0;
    buses = 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    while (true) {
        if (!getline(cin, s)) {
            solve();
            print();
            break;
        }
        if (s.empty()) {
            solve();
            print();
            reset();
        } else {
            M.emplace_back(s.begin(), s.end());
        }
    }


    return 0;
}
