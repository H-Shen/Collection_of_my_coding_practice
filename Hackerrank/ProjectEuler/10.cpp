#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;
const ll N = 1000003;
ll prime[N] = {0},num_prime = 0;
ll isNotPrime[N] = {1, 1};

unordered_map <ll, ll> table;

int main(void){
    for (ll i = 2 ; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++]=i;
        for(ll j = 0; j < num_prime && i * prime[j] <  N ; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }

    //Precomputation
    ll sum = 0;
    for (ll k = 0; k <= N; k++){
        if (isNotPrime[k] != 1) {
            sum += k;
            table[k] = sum;
        }
    }

    ll T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        while (1) {
            if (table.find(N) == table.end())
                N--;
            else {
                cout << table[N] << endl;
                break;
            }
        }

    }
    return 0;
}
