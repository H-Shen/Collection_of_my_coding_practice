// https://www.nowcoder.com/practice/b929be9dbbaa489a91afa3fec195c228

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > A;

int main() {

    ios_base::sync_with_stdio(false);
    int m, n, k;
    cin >> m >> n >> k;
    A.resize(m);
    for (auto &i : A) {
        i.resize(n);
    }
    for (auto &i : A) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    int current_i = 0;
    int current_j = n - 1;
    bool haveAns = false;
    while (current_i < m && current_j >= 0) {
        if (k < A[current_i][current_j]) {
            --current_j;
        } else if (k > A[current_i][current_j]) {
            ++current_i;
        } else {
            haveAns = true;
            break;
        }
    }
    if (haveAns) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
    return 0;
}