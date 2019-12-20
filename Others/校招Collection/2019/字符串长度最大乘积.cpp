// https://www.nowcoder.com/practice/480caa5ffd164ac8b71caaa6d0f4e6db

#include <bits/stdc++.h>

using namespace std;

inline
bool noDuplicate(const string &a, const string &b) {
    unordered_set<char> A(a.begin(), a.end());
    for (const auto &ch : b) {
        if (A.find(ch) != A.end()) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    unsigned long result = 0;

    try {
        char ch;
        string s;
        cin >> ch >> s;
        s.pop_back();

        vector<string> A;
        istringstream f(s);
        string temp;
        while (getline(f, temp, ',')) {
            temp = temp.substr(1, temp.size() - 2);
            A.emplace_back(temp);
        }

        for (size_t i = 0; i != A.size() - 1; ++i) {
            for (size_t j = i + 1; j != A.size(); ++j) {
                if (noDuplicate(A.at(i), A.at(j))) {
                    result = max(result, A.at(i).size() * A.at(j).size());
                }
            }
        }

    } catch (...) {

    }
    cout << result << endl;
    return 0;
}