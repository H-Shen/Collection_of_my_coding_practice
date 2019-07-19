#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

vector<vector<ll> > seqList;

int main() {

    ll N, Q, query;
    ll lastAns = 0;
    ll x, y, idx, len, val;
    scanf("%lld %lld", &N, &Q);
    seqList.resize(N);

    while (Q--) {
        scanf("%lld %lld %lld", &query, &x ,&y);
        idx = ((x ^ lastAns) % N);
        if (query == 1) {
            seqList[idx].push_back(y);
        }
        else {
            len = seqList[idx].size();
            val = (y % len);
            lastAns = seqList[idx][val];
            printf("%lld\n", lastAns);
        }
    }
    return 0;
}
