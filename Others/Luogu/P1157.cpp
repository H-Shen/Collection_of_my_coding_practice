#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<typename Itr>
inline static
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

int main() {

    int n, r;
    scanf("%d %d", &n, &r);
    vector<int> A(n);
    iota(A.begin(), A.end(), 1);
    do {
        for (int i = 0; i < r; ++i) {
            printf("%3d", A.at(i));
        }
        printf("\n");
    } while (next_combination(A.begin(), A.begin() + r, A.end()));
    
    return 0;
}

