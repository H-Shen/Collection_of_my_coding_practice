#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, sum;
    string s;
    cin >> n;
    set<int> res;
    while (n--) {
        cin >> s;
        sum = 0;
        for (const auto &ch : s) {
            sum = sum + static_cast<int>((ch - '0'));
        }
        res.insert(sum);
    }
    vector<int> resVec(res.begin(), res.end());
    cout << resVec.size() << endl;
    vector<int>::size_type i = 0;
    for (i = 0; i < resVec.size() - 1; ++i) {
        cout << resVec[i] << ' ';
    }
    cout << resVec.back() << endl;
    return 0;
}