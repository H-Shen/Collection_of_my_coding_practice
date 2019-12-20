#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string str;
    int a, b;
    unordered_map<int, pair<string, int> > A;

    cin >> n;
    while (n--) {
        cin >> str >> a >> b;
        pair<string, int> tmp;
        tmp.first = str;
        tmp.second = b;
        A[a] = tmp;
    }
    cin >> n;
    vector<int> L(n);
    for (auto &i : L) {
        cin >> i;
    }
    for (const auto &i : L) {
        cout << A[i].first << ' ' << A[i].second << endl;
    }
    return 0;
}