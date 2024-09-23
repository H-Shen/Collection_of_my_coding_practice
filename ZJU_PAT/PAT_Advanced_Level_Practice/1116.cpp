#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};

void preComputation() {

    int i;
    for (i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main() {
    preComputation();

    int n, i;
    unordered_map<string, int> A;
    string str;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> str;
        if (i == 1) {
            A[str] = 0;
        } else if (binary_search(prime, prime + num_prime, i)) {
            A[str] = 1;
        } else {
            A[str] = 2;
        }
    }
    int q;
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> str;
        if (A.find(str) == A.end()) {
            cout << str << ": Are you kidding?" << endl;
        } else if (A[str] == -1) {
            cout << str << ": Checked" << endl;
        } else if (A[str] == 0) {
            cout << str << ": Mystery Award" << endl;
            A[str] = -1;
        } else if (A[str] == 1) {
            cout << str << ": Minion" << endl;
            A[str] = -1;
        } else {
            cout << str << ": Chocolate" << endl;
            A[str] = -1;
        }
    }

    return 0;
}