// https://open.kattis.com/problems/avion
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 5;

int main() {

    vector<string> A;
    vector<int> result;
    string s;
    for (int i = 0; i < MAXN; ++i) {
        getline(cin, s);
        A.emplace_back(s);
    }

    for (int i = 0; i < MAXN; ++i) {
        if (A.at(i).find("FBI") != string::npos) {
            result.emplace_back(i + 1);
        }
    }

    if (result.empty()) {
        cout << "HE GOT AWAY!" << endl;
    } else {
        bool firstItem = true;
        for (const auto &it : result) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << it;
        }
        cout << endl;
    }

    return 0;
}
