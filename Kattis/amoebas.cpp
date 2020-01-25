// https://open.kattis.com/problems/amoebas
//
#include <bits/extc++.h>

using namespace std;

int convert(int col, int i, int j) {
    return col * i + j;
}
pair<int, int> rev_convert(int col, int val) {
    pair<int, int> ret;
    ret.first = val / col;
    ret.second = val % col;
    return ret;
}

vector<vector<char> > A;
unordered_set<int> save;

void go(int col, int x, int y) {
    try {
        if (A.at(x).at(y) == '#') {
            save.erase(convert(col, x, y));
            A.at(x).at(y) = '.';
            go(col, x + 1, y);
            go(col, x - 1, y);
            go(col, x, y - 1);
            go(col, x, y + 1);
            go(col, x + 1, y + 1);
            go(col, x + 1, y - 1);
            go(col, x - 1, y + 1);
            go(col, x - 1, y - 1);
        }
    } catch (...) {
        return;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    int n;
    string s;
    cin >> m >> n;
    cin.get();
    for (int i = 0; i < m; ++i) {
        getline(cin, s);
        vector<char> p(s.begin(), s.end());
        A.emplace_back(p);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A.at(i).at(j) == '#') {
                save.insert(convert(n, i, j));
            }
        }
    }
    int counter = 0;
    while (!save.empty()) {
        auto [i, j] = rev_convert(n, *save.begin());
        go(n, i, j);
        ++counter;
    }
    cout << counter << '\n';

    return 0;
}
