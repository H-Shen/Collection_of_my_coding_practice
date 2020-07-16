// https://open.kattis.com/problems/classy
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

unordered_map<string, int> level_mapping = {
        {"upper",  2},
        {"middle", 1},
        {"lower",  0}
};

struct Node {
    string name;
    vector<int> levels;
};

inline static
vector<int> split_by_char(string s, const char &delim) {
    vector<int> res;
    istringstream f(s);
    while (getline(f, s, delim)) {
        res.emplace_back(level_mapping[s]);
    }
    return res;
}

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    string name, levels, unused;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<Node> A(n);
        vector<int> temp;
        size_t max_length = 0;
        for (auto &i : A) {
            cin >> name >> levels >> unused;
            name.pop_back();
            i.name = name;
            i.levels = split_by_char(levels, '-');
            reverse(i.levels.begin(), i.levels.end());  // reverse the order
            max_length = max(max_length, i.levels.size());
        }
        // filling '1's to make sure they all have same length of class
        for (auto &i : A) {
            while (i.levels.size() < max_length) {
                i.levels.emplace_back(1);
            }
        }
        sort(A.begin(), A.end(), [](const Node &l, const Node &r) {
            for (size_t i = 0; i != l.levels.size(); ++i) {
                if (l.levels.at(i) == r.levels.at(i)) {
                    continue;
                }
                return l.levels.at(i) > r.levels.at(i);
            }
            return l.name < r.name;
        });
        // output
        for (const auto &[k, v] : A) {
            cout << k << '\n';
        }
        cout << "==============================" << '\n';
    }
    return 0;
}
