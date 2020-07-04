#include <bits/extc++.h>

using namespace std;
using ll = long long;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

unordered_map<int, int> A;

int main() {

    for (int i = 2, counter = 0; i <= 50; ++i) {
        if (is_prime(i)) {
            A[i] = counter;
            ++counter;
        }
    }
    int n, m;
    cin >> n >> m;
    if (A.find(n) != A.end() && A.find(m) != A.end() && A[n] == A[m] - 1) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
