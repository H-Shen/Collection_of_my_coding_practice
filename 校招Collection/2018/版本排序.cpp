// https://www.nowcoder.com/practice/f9daa556baa84997b3482755aaf63ec5

#include <regex>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 3;

inline
vector<int> getVector(const string &s) {
    vector<int> result(MAXN);
    istringstream f(s);
    string temp;
    size_t index = 0;
    while (getline(f, temp, '.')) {
        result.at(index++) = stoi(temp);
    }
    return result;
}

inline
string f(const string &s) {
    string result = "^";
    for (const auto &ch : s) {
        if (ch == '*') {
            result += ".*";
        } else if (ch == '.') {
            result += "\\.";
        } else {
            result += ch;
        }
    }
    result += "$";
    return result;
}

int main() {

    auto cmp = [](const string &lhs, const string &rhs) {
        vector<int> lhs_vec = getVector(lhs);
        vector<int> rhs_vec = getVector(rhs);
        if (lhs_vec.at(0) == rhs_vec.at(0)) {
            if (lhs_vec.at(1) == rhs_vec.at(1)) {
                return (lhs_vec.at(2) > rhs_vec.at(2));
            }
            return (lhs_vec.at(1) > rhs_vec.at(1));
        }
        return (lhs_vec.at(0) > rhs_vec.at(0));
    };

    ios_base::sync_with_stdio(false);
    int m;
    string s;
    cin >> m;
    vector<string> A(m);
    for (auto &&it : A) {
        cin >> it;
    }
    string pattern;
    cin >> pattern;
    pattern = f(pattern);
    regex R(pattern);

    vector<string> result;
    for (const auto &str : A) {
        if (regex_match(str, R)) {
            result.emplace_back(str);
        }
    }

    if (result.empty()) {
        cout << 0 << endl;
    } else {
        cout << *min_element(result.begin(), result.end(), cmp) << endl;
    }

    return 0;
}