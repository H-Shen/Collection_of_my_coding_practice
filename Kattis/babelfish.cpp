// https://open.kattis.com/problems/babelfish
#include <bits/extc++.h>

using namespace std;

inline
bool isEmpty(const string &s) {
    if (s.empty()) {
        return true;
    }
    for (const auto &ch : s) {
        if (ch != '\n' && ch != '\t' && ch != ' ') {
            return false;
        }
    }
    return true;
}

unordered_map<string, string> A;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while (getline(cin, s)) {
        if (isEmpty(s)) {
            break;
        }
        istringstream iss(s);
        vector<string> split((istream_iterator<string>(iss)),
                             istream_iterator<string>());
        A[split[1]] = split[0];
    }

    while (getline(cin, s)) {
        if (A.find(s) != A.end()) {
            cout << A[s] << endl;
        } else {
            cout << "eh" << endl;
        }
    }

    return 0;
}
