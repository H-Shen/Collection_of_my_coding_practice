#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    string a, b;
    cin >> n;
    unordered_map<string, string> A;

    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        A[a] = b;
    }

    int q;
    cin >> q;
    string c;
    unordered_set<string> B;
    for (i = 0; i < q; ++i) {
        cin >> c;
        B.insert(c);
    }


    for (const auto &it : A) {
        if (B.find(it.first) != B.end() &&
            B.find(it.second) != B.end()) {
            B.erase(it.first);
            B.erase(it.second);
        }
    }
    vector<string> res(B.begin(), B.end());
    sort(res.begin(), res.end());

    cout << res.size() << endl;
    if (!res.empty()) {
        for (i = 0; i < static_cast<int>(res.size()) - 1; ++i) {
            cout << res[i] << ' ';
        }
        cout << res[res.size() - 1] << endl;
    }
    return 0;
}
