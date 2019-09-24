// https://open.kattis.com/problems/kitten
//
#include <bits/stdc++.h>

using namespace std;

inline static
vector<int> parse(string s) {
    vector<int> result;
    string temp;
    istringstream iss(s);
    do {
        iss >> temp;
        result.emplace_back(stoi(temp));
    } while (iss);
    result.pop_back();
    return result;
}

int main() {


    ios_base::sync_with_stdio(false);
    int branch;
    string s;
    unordered_map<int, int> A;
    cin >> branch;
    cin.get();
    while (true) {
        getline(cin, s);
        if (s == "-1") {
            break;
        }
        auto p = parse(s);
        for (size_t i = 1; i != p.size(); ++i) {
            A[p[i]] = p[0];
        }
    }
    vector<int> result = {branch};
    while (A.find(result.back()) != A.end()) {
        result.emplace_back(A[result.back()]);
    }
    bool firstItem = true;
    for (const auto &i : result) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        cout << i;
    }
    cout << endl;

    return 0;
}
