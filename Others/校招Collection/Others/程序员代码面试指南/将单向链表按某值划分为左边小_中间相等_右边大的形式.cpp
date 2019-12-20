// https://www.nowcoder.com/practice/04fcabc5d76e428c8100dbd855761778

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n, pivot;
    cin >> n >> pivot;
    list<int> A(n);
    for (auto &&i : A) {
        cin >> i;
    }
    partition(partition(begin(A), end(A), [&](const int &val) {
        return (val < pivot);
    }), end(A), [&](const int &val) {
        return (val == pivot);
    });
    bool firstItem{true};
    for (const auto &i : A) {
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