#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
vector<string> splitByChar(string s, const char &delim) {
    for (char &ch : s) {
        if (ch == '\n' || ch == '\r' || ch == '\t') {
            ch = ' ';
        }
    }
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        if (!s.empty()) {
            res.emplace_back(s);
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<string, string> word2lang;
    string s, lang;
    getline(cin, s);
    int n = stoi(s);

    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        auto p = splitByChar(s, ' ');
        lang = p.front();
        for (size_t j = 1; j != p.size(); ++j) {
            for (auto &ch : p.at(j)) {
                ch = tolower(ch);
            }
            if (word2lang.find(p.at(j)) == word2lang.end()) {
                word2lang[p.at(j)] = lang;
            }
        }
    }
    getline(cin, s);    // eat the empty line
    while (getline(cin, s)) {
        for (auto &ch : s) {
            if (ch == '.' || ch == ',' || ch == '?' || ch == '!' || ch == ';' || ch == '(' || ch == ')') {
                ch = ' ';
            } else {
                ch = tolower(ch);
            }
        }
        auto p = splitByChar(s, ' ');
        for (const string &i : p) {
            if (word2lang.find(i) != word2lang.end()) {
                cout << word2lang[i] << '\n';
                break;
            }
        }
    }
    return 0;
}