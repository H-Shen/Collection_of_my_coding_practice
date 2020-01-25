// https://open.kattis.com/problems/busnumbers2
#include <bits/extc++.h>

using namespace std;
const int MAXN = 74;

int main() {

    ios_base::sync_with_stdio(false);
    unordered_map<int, int> A;
    unordered_set<string> filter;
    string s;
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = 1; j <= MAXN; ++j) {
            if (i <= j) {
                s = to_string(i) + ' ' + to_string(j);
            } else {
                s = to_string(j) + ' ' + to_string(i);
            }
            if (find(filter.begin(), filter.end(), s) == filter.end()) {
                ++A[i * i * i + j * j * j];
                filter.insert(s);
            }
        }
    }

    vector<int> L;
    for (const auto &it : A) {
        if (it.second > 1) {
            L.push_back(it.first);
        }
    }
    sort(L.begin(), L.end());
    L.pop_back();

    int n;
    cin >> n;
    if (binary_search(L.begin(), L.end(), n)) {
        cout << n;
    } else if (n < L.front()) {
        cout << "none";
    } else {
        auto bounds = equal_range(L.begin(), L.end(), n);
        cout << L[bounds.first - L.begin() - 1];
    }
    cout << endl;

    return 0;
}
