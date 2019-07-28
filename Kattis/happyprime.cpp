// https://open.kattis.com/problems/happyprime
#include<bits/stdc++.h>

using namespace std;

const int N = 10003;
int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};

//linearSieve
void linearSieve() {
    for (int i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

bool judge(int n) {
    int sum = 0;
    unordered_set<int> A;

    while (true) {
        sum = 0;
        while (n > 0) {
            sum = sum + (n % 10) * (n % 10);
            n /= 10;
        }
        if (sum == 1) {
            return true;
        } else if (A.find(sum) != A.end()) {
            return false;
        } else {
            n = sum;
            A.insert(sum);
        }
    }
}

int ans[10005] = {0};

int main() {
    linearSieve();
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= 10000; ++i) {
        if (isNotPrime[i] != 1 && judge(i)) {
            ans[i] = 1;
        }
    }

    int q, tmp, n;
    cin >> q;
    while (q--) {
        cin >> tmp >> n;
        cout << tmp << " " << n << " ";
        if (ans[n] == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
