// https://www.nowcoder.com/practice/8cb1f3979b524ed1ba67b4f64ed9e4f2

#include <bits/stdc++.h>

using namespace std;

const int N = 1000002;
const int num_doublePrime = 11200;
int prime[N];
int isNotPrime[N] = {1, 1};
int num_prime = 0;
int doublePrime[num_doublePrime];

inline
bool isDoublePrime(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    int n_rev = stoi(s);
    return (n != n_rev && !isNotPrime[n] && !isNotPrime[stoi(s)]);
}

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
    int counter = 0;
    for (int i = 0; i < num_prime; i++) {
        if (isDoublePrime(prime[i])) {
            doublePrime[counter++] = prime[i];

        }
    }

    // input
    int k;
    scanf("%d", &k);
    // output
    printf("%d\n", doublePrime[k - 1]);
    return 0;
}