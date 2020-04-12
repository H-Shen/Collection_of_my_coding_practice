#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// x    x: 0-9
// xx   x: 1-9999
// xyx  x: 1-1000 y: 0-9

const int N = 10005;
int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};

//linearSieve
void init() {
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

bool isPrime(const int &x) {
    for (int i = 0; i < num_prime; ++i) {
        if (x % prime[i] == 0 && x != prime[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    init();
    vector<int> A;
    string s, s_copy;
    int temp;
    for (int i = 5; i <= 9; ++i) {
        if (i % 2 != 0 && i % 3 != 0) {
            A.emplace_back(i);
        }
    }
    for (int i = 1; i <= 9999; ++i) {
        s = to_string(i);
        s_copy = s;
        reverse(s_copy.begin(), s_copy.end());
        temp = stoi(s + s_copy);
        A.emplace_back(temp);
    }
    for (char ch = '0'; ch <= '9'; ++ch) {
        for (int i = 1; i <= 1000; ++i) {
            s = to_string(i);
            s_copy = s;
            reverse(s_copy.begin(), s_copy.end());
            s += ch + s_copy;
            temp = stoi(s);
            A.emplace_back(temp);
        }
    }
    sort(A.begin(), A.end());
    vector<int> B;
    for (const auto &i : A) {
        if (isPrime(i)) {
            B.emplace_back(i);
        }
    }

    int a, b;
    scanf("%d %d", &a, &b);
    for (const auto &i : B) {
        if (i >= a && i <= b) {
            printf("%d\n", i);
        } else if (i > b) {
            break;
        }
    }
    return 0;
}
