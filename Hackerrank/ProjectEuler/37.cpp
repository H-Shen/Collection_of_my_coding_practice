#include <iostream>
using namespace std;

const int N = 1000003;
int prime[N] = {0},num_prime = 0;
int isNotPrime[N] = {1, 1};
int truncatablePrimes[N];

void pre(void){
    for (int i = 2 ; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++]=i;
        for(int j = 0; j < num_prime && i * prime[j] <  N ; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }

    return;
}

bool check(int n) {
    int n_copy = n;
    int current = 10;

    while (n_copy > 0) {
        if (isNotPrime[n_copy] == 1)
            return false;
        n_copy /= 10;
    }

    while (current < n) {
        int temp = n % current;
        current *= 10;
        if (isNotPrime[temp] == 1)
            return false;
    }
    return true;
}

void pre2(void) {
    int pos = 0;
    for (int i = 8; i < N; i++) {
        if (check(i)) {
            truncatablePrimes[pos++] = i;
        }
    }
}

int main() {
    pre();
    pre2();
    int N;
    int sum = 0;
    cin >> N;
    for (int i = 0; i < 11; i++)
        if (truncatablePrimes[i] < N)
            sum += truncatablePrimes[i];
    cout << sum << endl;
    return 0;
}
