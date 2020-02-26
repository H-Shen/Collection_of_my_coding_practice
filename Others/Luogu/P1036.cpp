#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace EulerPrimeSieve {

    const int MAXN = 10000005;
    int prime[MAXN] = {0};
    int num_prime = 0;
    bool isNotPrime[MAXN] = {true, true};

    // Generate the prime table from 1 to MAXN
    inline static
    void init() {
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = true;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
}

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

    EulerPrimeSieve::init();
    int n, k, val;
    scanf("%d %d", &n, &k);
    vector<int> index2element;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        A.at(i) = i;
        index2element.emplace_back(val);
    }
    int sum;
    int counter = 0;
    do {
        sum = 0;
        for (int i = 0; i < k; i++) {
            sum += index2element.at(A.at(i));
        }
        if (!EulerPrimeSieve::isNotPrime[sum]) {
            ++counter;
        }
    } while (next_combination(A.begin(), A.begin() + k, A.end()));
    printf("%d\n", counter);

    return 0;
}

