template<typename Itr>
bool next_combination(const Itr &first, Itr k, const Itr &last) {
    if ((first == last) || (first == k) || (last == k))
        return false;
    Itr iter1 = first, iter2 = last;
    ++iter1;
    if (last == iter1) return false;
    iter1 = k;
    --iter2;
    while (first != iter1) {
        if (*--iter1 < *iter2) {
            Itr j = k;
            while (!(*iter1 < *j)) ++j;
            std::iter_swap(iter1, j);
            ++iter1;
            ++j;
            iter2 = k;
            std::rotate(iter1, j, last);
            while (last != j) ++j, ++iter2;
            std::rotate(k, iter2, last);
            return true;
        }
    }
    std::rotate(first, k, last);
    return false;
}

using ll = long long;
ll comb(ll n, ll m) {
    if (m > n - m) m = n - m;
    ll result = 1;
    for (ll i = 1; i <= m; ++i) {
        result = result * (n - m + i) / i;
    }
    return result;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> A(n);
        vector<vector<int>> ans(comb(n,k));
        auto iter = ans.begin();
        iota(A.begin(),A.end(),1);
        vector<int> vec(k);
        do {
            for (int i = 0; i < k; ++i) {
                vec[i] = A[i];
            }
            *iter = vec;
            ++iter;
        } while (next_combination(A.begin(),A.begin()+k,A.end()));
        return ans;
    }
};