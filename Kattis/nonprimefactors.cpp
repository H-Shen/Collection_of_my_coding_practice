// https://open.kattis.com/problems/nonprimefactors

#include <bits/extc++.h>

using namespace std;

const int N = 2000000 + 5;
int NPF[N];
int prime[N];
int isNotPrime[N] = {1, 1};
int num_prime = 0;

inline
void getPrimes() {
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
}

inline
void getNPFs() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; i * j < N; j++) {
            if (isNotPrime[i]) {
                NPF[i * j] += 1;
            }
        }
    }
}

int main() {

    getPrimes();
    getNPFs();

    int Q, a;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &a);
        printf("%d\n", NPF[a]);
    }

    return 0;
}
