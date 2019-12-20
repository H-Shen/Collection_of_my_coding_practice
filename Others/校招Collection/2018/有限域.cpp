// https://www.nowcoder.com/practice/6f4a5a8e760b4132afc99faee2e025b0

#include <cmath>
#include <cstdio>

using namespace std;

const int N = 10003;
int prime[N];
int isNotPrime[N] = {1, 1};
int num_prime = 0;

// check if a^x = b
inline
bool isPower(int a, int b) {

    if (a == 0) {
        return false;
    }

    int x = static_cast<int>(log(static_cast<double>(b)) / log(static_cast<double>(a)));
    int sum = a;
    for (int i = 0; i < x; ++i) {
        sum *= a;
    }
    if (sum == b) {
        return true;
    }

    sum = a;
    for (int i = 0; i < x - 1; ++i) {
        sum *= a;
    }
    if (sum == b) {
        return true;
    }

    sum = a;
    for (int i = 0; i < x + 1; ++i) {
        sum *= a;
    }
    return sum == b;
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

    // get input
    int n;
    scanf("%d", &n);
    int counter = 0;
    for (int i = 2; i <= n; i++) {
        // check if it is a power of prime
        for (int k = 0; k < num_prime; k++) {
            if (prime[k] > i) {
                break;
            }
            if (isPower(prime[k], i)) {
                ++counter;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}
