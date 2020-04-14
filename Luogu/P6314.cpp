#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 9;
constexpr int SUM = 100;

template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last) {
    if ((first == last) || (first == k) || (last == k))
        return false;
    Iterator itr1 = first;
    Iterator itr2 = last;
    ++itr1;
    if (last == itr1)
        return false;
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

array<int, MAXN> A;
unordered_map<int, int> val2idx;

int main() {

    for (int i = 0; i < MAXN; ++i) {
        scanf("%d", &A.at(i));
        val2idx[A.at(i)] = i;
    }
    sort(A.begin(), A.end());
    int comb_size = 7;
    int sum;
    do {
        sum = accumulate(A.begin(), A.begin() + comb_size, 0);
        if (sum == 100) {
            vector<int> output(A.begin(), A.begin() + comb_size);
            sort(output.begin(), output.end(), [](const int &l, const int &r){
                return val2idx[l] < val2idx[r];
            });
            for (const auto &i : output) {
                printf("%d\n", i);
            }
            break;
        }
    } while (next_combination(A.begin(), A.begin() + comb_size, A.end()));

    return 0;
}
