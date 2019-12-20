// https://ac.nowcoder.com/acm/contest/234/D

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) {
        cin >> i;
    }
    set<int> output(A.begin(), A.end());
    cout << output.size() << endl;
    bool firstItem = true;
    for (const auto &i : output) {
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