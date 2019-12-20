#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    ll sale;
    cin >> N >> M;
    vector<ll> saleSumList(static_cast<size_t>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> sale;
            saleSumList[j] += sale;
        }
    }

    // exception
    if (!M) {
        cout << 0 << endl;
        return 0;
    }

    ll maxSaleSum = *max_element(saleSumList.begin(), saleSumList.end());
    cout << maxSaleSum << endl;

    bool firstAnswer = true;
    for (int i = 0; i < N; ++i) {
        if (saleSumList[i] == maxSaleSum) {
            if (firstAnswer) {
                cout << i + 1;
                firstAnswer = false;
            } else {
                cout << " " << i + 1;
            }
        }
    }
    cout << endl;
}