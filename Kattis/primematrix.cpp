// https://open.kattis.com/problems/primematrix
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 5000;

set<int> primes = {2};

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

deque<int> solve(int n) {
    deque<int> result(n);
    iota(result.begin(), result.end(), 1);
    int sum = (1 + n) * n / 2;
    int dist = *primes.lower_bound(sum) - sum;
    // use greedy here!
    auto iter = result.rbegin();
    while (dist > 0) {
        *iter += 1;
        --dist;
        ++iter;
        if (iter == result.rend()) {
            iter = result.rbegin();
        }
    }
    return result;
}

deque<deque<int> > generate(deque<int> A) {
    deque<deque<int> > result;
    for (size_t i = 0; i != A.size(); ++i) {
        result.emplace_back(A);
        A.push_back(A.front());
        A.pop_front();
    }
    return result;
}


int main() {

    // pre
    for (int i = 3; i <= MAXN; ++i) {
        if (is_prime(i)) {
            primes.insert(i);
        }
    }

    int n, b;
    scanf("%d %d", &n, &b);
    auto p = solve(n);
    if (*max_element(p.begin(), p.end()) > b) {
        printf("impossible\n");
        return 0;
    }
    auto result = generate(p);
    bool first_item;
    for (const auto &i : result) {
        first_item = true;
        for (const auto &j : i) {
            if (first_item) {
                first_item = false;
            } else {
                printf(" ");
            }
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
