#include <bits/stdc++.h>

using namespace std;

const int N = 104730;

int prime[N] = {0},num_prime = 0;
int isNotPrime[N] = {1, 1};

void preComputation() {

    int i;
    for (i = 2 ; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++]=i;
        for(int j = 0; j < num_prime && i * prime[j] <  N ; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    preComputation();
    int T, pos;
    cin >> T;
    while (T--) {
        cin >> pos;
        cout << prime[pos - 1] << endl;
    }
    return 0;
}
