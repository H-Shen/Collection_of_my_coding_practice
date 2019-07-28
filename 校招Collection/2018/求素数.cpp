// https://www.nowcoder.com/practice/ea1c82be0c144d74925a044973fe9a5c

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
    int m, n, m_pos, n_pos;
    scanf("%d %d", &m, &n);

    if (m < prime[0]) {
        m_pos = 0;
    } else {
        m_pos = upper_bound(prime, prime + num_prime, m) - prime - 1;
    }

    if (n < prime[0]) {
        n_pos = 0;
    } else {
        n_pos = upper_bound(prime, prime + num_prime, n) - prime - 1;
    }

    printf("%d\n", n_pos - m_pos + 1);
    return 0;
}