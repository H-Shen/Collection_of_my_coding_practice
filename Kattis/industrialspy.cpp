// https://open.kattis.com/problems/industrialspy
//
#include <bits/stdc++.h>

using namespace std;

namespace LinearSieve {

    constexpr int N = 10000001;
    int num_prime = 0;
    int *isNotPrime = nullptr;
    int *prime = nullptr;

    //linearSieve
    void pre() {

        // allocation
        isNotPrime = new int[N]();
        isNotPrime[0] = 1;
        isNotPrime[1] = 1;
        prime = new int[664581]();

        for (int i = 2; i < N; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
                isNotPrime[i * prime[j]] = 1;
                if (!(i % prime[j]))
                    break;
            }
        }

        // release
        delete[] prime;
        prime = nullptr;
    }
}

template<typename Iterator>
/* Credits: Mark Nelson http://marknelson.us */
inline bool
next_combination(const Iterator first, Iterator k, const Iterator last) {
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
            iter_swap(itr1, j);
            ++itr1;
            ++j;
            itr2 = k;
            rotate(itr1, j, last);
            while (last != j) {
                ++j;
                ++itr2;
            }
            rotate(k, itr2, last);
            return true;
        }
    }
    rotate(first, k, last);
    return false;
}

constexpr int MAX_LENGTH = 10;
char str[MAX_LENGTH];
unordered_set<int> stats;

int main() {

    LinearSieve::pre();
    string s;
    string sub;
    int t;
    int convert;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        s = str;
        sort(s.begin(), s.end());
        string_view sv(s);
        stats.clear();
        for (size_t comb_size = 0; comb_size <= s.size(); ++comb_size) {
            do {
                sub = sv.substr(comb_size);
                if (!sub.empty()) {
                    do {
                        convert = stoi(sub);
                        if (!LinearSieve::isNotPrime[convert]) {
                            stats.insert(convert);
                        }
                    } while (next_permutation(sub.begin(), sub.end()));
                }
            } while (next_combination(s.begin(), s.begin() + comb_size,
                                      s.begin() + s.size()));
        }
        printf("%d\n", static_cast<int>(stats.size()));
    }

    return 0;
}
