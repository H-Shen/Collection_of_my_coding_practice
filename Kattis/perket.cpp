// https://open.kattis.com/problems/perket
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename Iterator>
/* Credits: Mark Nelson http://marknelson.us */
inline bool next_combination(const Iterator first, Iterator k, const Iterator last) {
    if ((first == last) || (first == k) || (last == k))
        return false;
    Iterator itr1 = first;
    Iterator itr2 = last;
    ++itr1;
    if (last == itr1)
        return false;
    itr1 = last;
    --itr1;
    itr1 = k;
    --itr2;
    while (first != itr1) {
        if (*--itr1 < *itr2) {
            Iterator j = k;
            while (!(*itr1 < *j)) ++j;
            iter_swap(itr1,j);
            ++itr1;
            ++j;
            itr2 = k;
            rotate(itr1,j,last);
            while (last != j) {
                ++j;
                ++itr2;
            }
            rotate(k,itr2,last);
            return true;
        }
    }
    rotate(first,k,last);
    return false;
}


int main() {

    int n;
    scanf("%d", &n);
    vector<pair<ll, ll> > A(n);
    for (auto &i : A) {
        scanf("%lld %lld", &i.first, &i.second);
    }

    vector<int> L(n);
    iota(L.begin(), L.end(), 0);
    size_t comb_size_max = n;
    ll bitterness;
    ll sourness;
    ll minVal = numeric_limits<ll>::max();
    for (size_t comb_size = 1; comb_size <= comb_size_max; ++comb_size) {
        do {
            bitterness = 0;
            sourness = 1;
            // get difference
            for (size_t i = 0; i != comb_size; i++) {
                bitterness += A[L[i]].second;
                sourness *= A[L[i]].first;
            }
            minVal = min(minVal, abs(sourness - bitterness));
        } while (next_combination(L.begin(), L.begin() + comb_size,
                                  L.begin() + L.size()));
    }
    printf("%lld\n", minVal);
    return 0;
}
