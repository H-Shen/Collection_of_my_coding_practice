// https://ac.nowcoder.com/acm/problem/14320

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    vector<vector<ll> > A;
    vector<ll> temp;
    A.emplace_back(vector<ll>{1});
    A.emplace_back(vector<ll>{1, 1});

    while (A.size() != 35) {
        vector<ll> tempNext = {1};
        for (size_t i = 0; i != A.back().size() - 1; ++i) {
            tempNext.emplace_back(A.back().at(i) + A.back().at(i + 1));
        }
        tempNext.emplace_back(1);
        A.emplace_back(tempNext);
    }

    size_t n;
    bool firstItem;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        firstItem = true;
        for (const auto &j : A.at(i)) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << j;
        }
        cout << endl;
    }

    return 0;
}