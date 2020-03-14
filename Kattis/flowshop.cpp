// https://open.kattis.com/problems/flowshop
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<ll> > P(n, vector<ll>(m));
    for (auto &i : P) {
        for (auto &j : i) {
            scanf("%lld", &j);
        }
    }
    vector<ll> cost(n);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                cost.at(i) += P.at(i).at(j);
            }
            else if (cost.at(i) > cost.at(i - 1)) {
                cost.at(i) += P.at(i).at(j);
            }
            else {
                cost.at(i) = P.at(i).at(j) + cost.at(i - 1);
            }
        }
    }
    bool first_item = true;
    for (int i = 0; i < n; ++i) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%lld", cost.at(i));
    }
    printf("\n");

    return 0;
}
