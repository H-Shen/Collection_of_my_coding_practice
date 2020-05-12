#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_set<string> A;

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    string word;
    while (n--) {
        cin >> word;
        for (auto &ch : word) {
            ch = tolower(ch);
        }
        A.insert(word);
    }
    cin.get();
    string s;
    getline(cin, s);
    for (auto &ch : s) {
        if (ch == ',') {
            ch = ' ';
        } else {
            ch = tolower(ch);
        }
    }
    auto p = splitByChar(s, '.');
    int counter = 0;
    for (const auto &i : p) {
        auto p_ = splitByChar(i, ' ');
        unordered_set<string> history;
        for (const auto &j : p_) {
            if (A.find(j) != A.end()) {
                if (history.find(j) == history.end()) {
                    history.insert(j);
                    ++counter;
                }
            }
        }
    }
    cout << counter << '\n';
    return 0;
}
