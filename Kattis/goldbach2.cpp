// https://open.kattis.com/problems/goldbach2
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 33003;
int prime[N] = {0},num_prime = 0;
int isNotPrime[N] = {1, 1};

//linearSieve
void linearSieve()
{
    for (int i = 2 ; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++]=i;
        for(int j = 0; j < num_prime && i * prime[j] <  N ; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    linearSieve();
    int n, val;
    int middle = 0;
    int middlePrime = 0;
    int middlePrimePos = 0;
    cin >> n;
    for (int kase = 0; kase < n; ++kase)
    {
        cin >> val;
        middle = val / 2;

        for (int i = middle; i >= 2; --i)
        {
            if (isNotPrime[i] != 1)
            {
                middlePrime = i;
                break;
            }
        }

        middlePrimePos = lower_bound(prime, prime + num_prime, middlePrime)
                       - prime;
        vector < pair <int, int> > res;
        for (int i = 0; i <= middlePrimePos; ++i)
        {
            if (isNotPrime[val - prime[i]] != 1)
            {
                res.push_back(make_pair(prime[i], val - prime[i]));
            }
        }
        cout << val << " has " << res.size() << " representation(s)" << endl;
        for (const auto &it : res)
        {
            cout << it.first << "+" << it.second << endl;
        }
        if (kase != n - 1)
        {
            cout << endl;
        }
    }
    return 0;
}
