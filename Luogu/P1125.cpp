#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 105;
constexpr int MAX = 500;
char cstr[MAXN];

unordered_set<int> primes;
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    for (int i = 1; i <= MAX; ++i) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }

    scanf("%s", cstr);
    string s(cstr);
    unordered_map<char, int> A;
    for (const char &ch : s) {
        ++A[ch];
    }
    int maxn = numeric_limits<int>::min();
    for (const auto &[k, v] : A) {
        maxn = max(maxn, v);
    }
    int minn = numeric_limits<int>::max();
    for (const auto &[k, v] : A) {
        minn = min(minn, v);
    }
    int dist = maxn - minn;
    if (primes.find(dist) != primes.end()) {
        printf("Lucky Word\n%d\n", dist);
    } else {
        printf("No Answer\n0\n");
    }

    return 0;
}

