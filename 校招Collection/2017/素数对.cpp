// https://www.nowcoder.com/practice/c96d6acc025541ffb79c579688f8d003

#include <cstdio>

using namespace std;

const int N = 1010;
int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};

void pre() {
    for (int i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
    return;
}

int main() {

    pre();
    int Pair = 0;
    int n, i, j;
    scanf("%d", &n);

    if (n % 2 == 0) {
        for (i = 2; i <= n / 2; i++) {
            j = n - i;
            if (isNotPrime[i] != 1 && isNotPrime[j] != 1) {
                Pair++;
            }
        }
    } else {
        for (i = 2; i < n / 2 + 1; i++) {
            j = n - i;
            if (isNotPrime[i] != 1 && isNotPrime[j] != 1) {
                Pair++;
            }
        }
    }
    printf("%d\n", Pair);
    return 0;
}