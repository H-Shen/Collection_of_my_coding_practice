#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

vector<ll> Fib = {
        1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
        2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418,
        317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465,
        14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296,
        433494437, 701408733, 1134903170
};

// Zeckendorf's theorem: Every positive integer can be represented uniquely as
// the sum of one or more distinct Fibonacci numbers in such a way that
// the sum does not include any two consecutive Fibonacci numbers.
//
// For any given positive integer, a representation that satisfies the
// conditions of Zeckendorf's theorem can be found by using a greedy algorithm,
// choosing the largest possible Fibonacci number at each stage.
vector<ll> partition(ll n) {
    vector<ll> result;
    while (n > 0) {
        auto iter = upper_bound(Fib.begin(), Fib.end(), n);
        --iter;
        result.emplace_back(*iter);
        n -= *iter;
    }
    reverse(result.begin(), result.end());
    return result;
}

inline static
void join_output(const vector<ll> &v, const char &ch) {
    for (auto p = cbegin(v); p != cend(v); ++p) {
        printf("%lld", *p);
        if (p != cend(v) - 1) {
            putchar_unlocked(ch);
        }
    }
}

int main() {

    int t;
    ll val;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &val);
        auto p = partition(val);
        if (p.size() == 1) {
            printf("%lld=%lld", val, val);
        } else {
            printf("%lld=", val);
            join_output(p, '+');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
