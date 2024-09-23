#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first > b.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, i, diff;
    cin >> n;
    vector<int> A(static_cast<size_t>(n));

    for (i = 0; i < n; ++i) {
        cin >> A[i];
    }

    unordered_map<int, int> freqSave;
    for (i = 0; i < n; ++i) {
        diff = abs(i + 1 - A[i]);
        ++freqSave[diff];
    }

    vector<pair<int, int> > freqSaveVec;
    for (auto it = freqSave.cbegin(); it != freqSave.cend(); ++it) {
        if (it->second != 1) {
            freqSaveVec.emplace_back(make_pair(it->first, it->second));
        }
    }
    sort(freqSaveVec.begin(), freqSaveVec.end(), cmp);
    for (const auto &p : freqSaveVec) {
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}