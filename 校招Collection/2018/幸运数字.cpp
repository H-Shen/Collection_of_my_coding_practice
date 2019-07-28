// https://www.nowcoder.com/practice/69682e8bd0654795955c2e478b988f93

#include <bits/stdc++.h>

using namespace std;
const string MAXVAL = "888888888";

inline
vector<string> add(const vector<string> &A) {
    vector<string> result(A.begin(), A.end());
    result.resize(result.size() * 2);
    copy(A.begin(), A.end(), result.begin() + result.size() / 2);

    // add '6'
    for (size_t i = 0; i != result.size() / 2; ++i) {
        result.at(i) += "6";
    }
    // add '8'
    for (size_t i = result.size() / 2; i != result.size(); ++i) {
        result.at(i) += "8";
    }

    return result;
}

int main() {
    vector<string> A = {"6", "8"};
    vector<string> temp = A;

    while (A.back() != MAXVAL) {
        temp = add(temp);
        for (const string &i : temp) {
            A.emplace_back(i);
        }
    }

    vector<int> A_int(A.size());
    for (size_t i = 0; i != A_int.size(); ++i) {
        A_int.at(i) = stoi(A.at(i));
    }

    int a, b;
    string a_str, b_str;
    try {
        cin >> a_str >> b_str;
        a = stoi(a_str);
        b = stoi(b_str);

        if (a > b) {
            throw invalid_argument("");
        }

        int counter = 0;
        for (const int &i : A_int) {
            if (i >= a && i <= b) {
                ++counter;
            }
        }
        cout << counter << endl;
    } catch (...) {
        cout << -1 << endl;
    }

    return 0;
}
