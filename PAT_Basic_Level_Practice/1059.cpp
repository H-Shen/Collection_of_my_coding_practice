#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
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
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();

    unordered_map<string, string> A;
    int n, i, query;
    string tmp;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> tmp;
        if (i == 1) {
            A[tmp] = "Mystery Award";
        } else if (isNotPrime[i] == 0) {
            A[tmp] = "Minion";
        } else {
            A[tmp] = "Chocolate";
        }
    }
    cin >> query;
    while (query--) {
        cin >> tmp;
        if (A.find(tmp) == A.end()) {
            cout << tmp << ": Are you kidding?";
        } else if (A[tmp] == "-1") {
            cout << tmp << ": Checked";
        } else {
            cout << tmp << ": " << A[tmp];
            A[tmp] = "-1";
        }
        cout << endl;
    }
    return 0;
}