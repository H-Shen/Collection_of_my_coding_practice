#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr char CARRIAGE_RETURN = 13;

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

unordered_set<string> A;
unordered_map<string, int> stats;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    string s;
    getline(cin, s);
    auto p = splitByChar(s, ' ');
    if (p.size() > 1) {
        n = stoi(p.front());
        m = stoi(p.back());
    } else {
        n = stoi(p.front());
        getline(cin, s);
        p = splitByChar(s, ' ');
        m = stoi(p.front());
    }
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        // Fix the issue in this problem
        if (s.back() != CARRIAGE_RETURN) {
            s.push_back(CARRIAGE_RETURN);
        }
        A.insert(s);
    }
    for (int i = 0; i < m; ++i) {
        getline(cin, s);
        // Fix the issue in this problem
        if (s.back() != CARRIAGE_RETURN) {
            s.push_back(CARRIAGE_RETURN);
        }
        ++stats[s];
    }
    int counter = 0;
    for (const auto &[k, v] : stats) {
        if (A.find(k) != A.end()) {
            counter += v;
        }
    }
    cout << counter << '\n';

    return 0;
}
