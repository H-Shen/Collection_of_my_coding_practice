// https://www.nowcoder.com/practice/9e7a88d6a00e404c8418602515a5046c

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000002;
int prime[N];
int isNotPrime[N] = {1, 1};
int num_prime = 0;

int main() {

    // pre
    for (int i = 2; i < N; i++) {
        if (!isNotPrime[i]) {
            prime[num_prime++] = i;
        }
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j])) {
                break;
            }
        }
    }

    // get input
    int n, n_pos;
    scanf("%d", &n);

    if (n < prime[0]) {
        n_pos = 0;
    } else {
        n_pos = upper_bound(prime, prime + num_prime, n) - prime - 1;
        if (binary_search(prime, prime + num_prime, n)) {
            --n_pos;
        }
    }

    printf("%d\n", n_pos + 1);
    return 0;
}