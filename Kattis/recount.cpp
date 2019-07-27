// https://open.kattis.com/problems/recount

#include<bits/stdc++.h>

using namespace std;
const int minVal = -1;
unordered_map<string, int> A;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while (1) {
        getline(cin, s);
        if (s == "***") {
            break;
        }
        ++A[s];
    }
    int maxVal = minVal;
    for (const auto &i : A) {
        maxVal = max(maxVal, i.second);
    }
    vector<string> res;
    for (const auto &i : A) {
        if (i.second == maxVal) {
            res.push_back(i.first);
        }
    }
    if (res.size() != 1) {
        cout << "Runoff!" << endl;
    } else {
        cout << res[0] << endl;
    }
    return 0;
}
