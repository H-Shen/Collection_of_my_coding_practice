#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5000000;

unsigned int A[MAXN];

void randomize(unsigned int a, unsigned int b, unsigned int mod) {
    for (unsigned int &i : A) {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        i = ((a << 16) + b) % mod;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    unsigned int a, b, mod, k;
    cin >> a >> b >> mod >> k;
    randomize(a, b, mod);

    nth_element(A, A + k - 1, A + MAXN);
    cout << A[k - 1] << '\n';

    return 0;
}